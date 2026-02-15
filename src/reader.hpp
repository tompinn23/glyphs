#pragma once

#include <string>
#include <fstream>
#include <efsw/Watcher.hpp>


#include "events/common.hpp"

#include "registry.hpp"
#include <chrono>

#include "atomicops.h"
#include "process.h"
#include "queue.h"
#include "reader_state.hpp"



namespace hue {

	using namespace nlohmann;

	struct startup {
		std::string timestamp;
		std::string event;
		std::string star_system;
		std::vector<double> star_pos;
		int64_t system_address;
		int64_t system_population;

		std::optional<std::string> body;
		std::optional<int64_t> body_id;
		std::optional<std::string> body_type;

		bool docked;
		std::optional<int64_t> market_id;
		std::optional<std::string> station_name;
		std::optional<std::string> station_type;
	};

	inline void to_json(json &j, const startup& x) {
		j = json::object();
		j["timestamp"] = x.timestamp;
		j["event"] = x.event;
		j["StarSystem"] = x.star_system;
		j["StarPos"] = x.star_pos;
		j["SystemAddress"] = x.system_address;
		j["SystemPopulation"] = x.system_population;
		j["Body"] = x.body;
		j["BodyID"] = x.body_id;
		j["BodyType"] = x.body_type;
		j["MarketId"] = x.market_id;
		j["StationName"] = x.station_name;
		j["StationType"] = x.station_type;
	}

	struct journal_file {
		explicit journal_file() {
			file = nullptr;
			pos = 0;
		}

		explicit journal_file(const std::filesystem::path& p) {
			file = fopen(p.string().c_str(), "rb");
			pos = 0;
			if (!file) {
				throw std::runtime_error("Could not open file");
			}
		}

		journal_file(const journal_file&) = delete;
		journal_file& operator=(const journal_file&) = delete;

		~journal_file() {
			close();
		}

		journal_file(journal_file&& other) noexcept
			: file(other.file),
			  pos(other.pos)
		{
			other.file = nullptr;
			other.pos = 0;
		}

		journal_file& operator=(journal_file&& other) noexcept {
			if (this != &other) {
				if (file) std::fclose(file);

				file = other.file;
				pos  = other.pos;

				other.file = nullptr;
				other.pos = 0;
			}
			return *this;
		}

		[[nodiscard]] bool is_open() const { return file != nullptr; }

		void close() {
			if (file) {
				fclose(file);
				file = nullptr;
			}
		}

		std::optional<std::string> readline() {
			if (!file) return std::nullopt;

			std::fseek(file, pos, SEEK_SET);

			std::string out;
			out.reserve(256);

			int c = std::fgetc(file);
			if (c == EOF) return std::nullopt;


			while (c != EOF && c != '\n' && c != '\r') {
				out.push_back((char)c);
				c = std::fgetc(file);
			}

			if (c == '\r') {
				int c2 = std::fgetc(file);
				if (c2 != '\n') {
					// lone \r
					std::ungetc(c2, file);
				}
			}
			pos = std::ftell(file);
			return out;
		}
	private:
		FILE* file = nullptr;
		long pos = 0;
	};


	struct semantic_version {
		int major = 0;
		int minor = 0;
		int patch = 0;
		std::string prerelease;
		std::string build;
		bool valid = false;
	};

		template <typename T>
	class exclusive {
	public:
		struct handle {
			T* ptr = nullptr;
			std::atomic<bool>* lock = nullptr;

			handle() = default;

			handle(handle&& other) noexcept {
				ptr = other.ptr;
				lock = other.lock;
				other.ptr = nullptr;
				other.lock = nullptr;
			}

			handle& operator=(handle&& other) noexcept {
				if (this != &other) {
					release();
					ptr = other.ptr;
					lock = other.lock;
					other.ptr = nullptr;
					other.lock = nullptr;
				}
				return *this;
			}

			handle(T* p, std::atomic<bool>* t)
				: ptr(p), lock(t) {}

			handle(const handle&) = delete;
			handle& operator=(const handle&) = delete;

			~handle() {
				release();
			}

			void release() {
				if (lock) {
					lock->store(false, std::memory_order_release);
					ptr = nullptr;
					lock = nullptr;
				}
			}

			T* operator->() { return ptr; }
			T& operator*()  { return *ptr; }

			explicit operator bool() const { return ptr != nullptr; }
		};

		// Try to acquire exclusive ownership
		handle acquire() {
			bool expected = false;
			if (!taken_.compare_exchange_strong(expected, true,
												std::memory_order_acq_rel))
			{
				return {};
			}
			return handle{ &resource_, &taken_ };
		}

		T& raw() {
			return resource_;
		}

		const T& raw() const {
			return resource_;
		}

		explicit exclusive(T resource) : resource_(std::move(resource)) {}

	private:
		T resource_;
		std::atomic<bool> taken_{false};
	};

	struct reader: public efsw::FileWatchListener {
		using queue_type = moodycamel::BlockingReaderWriterQueue<std::pair<game_state, event>>;
		using timestamp = std::chrono::sys_time<std::chrono::milliseconds>;

	    struct file_event {
	        explicit file_event(const std::chrono::seconds delta, std::function<event(event)> action)
		        : delta(delta), action(action) {
	        }

	        std::optional<event> journal_arrived(event ev, const reader::timestamp& ts) {
	            journal = std::move(ev);
	            journal_timestamp = ts;
	            has_journal = true;

	            if (has_file && within_delta(journal_timestamp, file_timestamp)) {
	                clear_pending();
	                return std::move(file);
	            }

	            return std::nullopt;
	        }

	        std::optional<event> file_arrived(event ev, const reader::timestamp& ts) {
	            file = std::move(ev);
	            file_timestamp = ts;
	            has_file = true;

	            if (has_journal && within_delta(journal_timestamp, file_timestamp)) {
	            	clear_pending();
	            	return std::move(file);
	            }

	            return std::nullopt;
	        }
	    private:
	        bool within_delta(std::chrono::system_clock::time_point a,
	                  std::chrono::system_clock::time_point b) const {
	            const auto diff = a > b ? (a - b) : (b - a);
	            return diff <= delta;
	        }

	        void clear_pending() {
	            has_file = false;
	            has_journal = false;
	        }

	        std::optional<event> journal;
	        timestamp journal_timestamp;
	        std::optional<event> file;
	        timestamp file_timestamp;

	        bool has_journal = false;
	        bool has_file = false;

	        std::chrono::seconds delta;
	    	std::function<event(event)> action;
	    };

		bool init = false;
		bool replay = false;
		bool live;
		bool is_beta;
		bool game_was_running;


		std::string cmdr;
		std::string mode;
		std::string group;
		std::string version;

		semantic_version semver;

		std::vector<std::string> station_services;
		timestamp started;
		game_state state;
		std::string slef;

		std::unordered_map<int64_t, std::string> carrier_ids;

		exclusive<queue_type> queue;

		explicit reader(const std::string& journal_dir);
		void replay_file();
		void handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& file, efsw::Action action, std::string old) override;

		exclusive<queue_type>::handle acquire() {
			return queue.acquire();
		}


	private:
		file_event cargo_event;
		file_event backpack_event;
		file_event market_event;
		file_event shipyard_event;
		file_event navroute_event;
		file_event outfitting_event;
		file_event fcmaterials_event;
		file_event moduleinfo_event;

		process running_process;

		std::string journal_dir;
		std::string logfile;
		journal_file loghandle;

		event_parser events = event_parser();


		template<class T>
		std::vector<T> coalesce(const std::vector<T> &input);

		event on_file(event event);

		static std::string newest_journal(const std::string& journal_dir);

		event synthesize_startup_event();

		std::pair<event, reader::timestamp> from_file(const std::string &filename);

		void put_event(event event);

		std::optional<event> parse_entry(const std::string& line);

		std::string suit_sane_name(const std::string &in);

		std::tuple<int64_t, int64_t> suit_loadout_store_from_event(event event);

		int64_t suit_loadout_id_from_loadout_id(int64_t loadout_id);

		std::optional<std::string> get_callsign(int64_t carrier_id);

		void populate_version_info(event &event, bool suppress);

		std::string category(std::string item);

		static std::string canonicalise(const std::string &item) ;
		static timestamp parse_iso8601(const std::string& s);
	};
}

