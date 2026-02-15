#include "reader.hpp"
#include <efsw/efsw.hpp>
#include "spdlog/spdlog.h"


int main(int argc, char **argv) {

    const std::string DIR = R"(C:\Users\pooh\Saved Games\Frontier Developments\Elite Dangerous)";

    spdlog::set_level(spdlog::level::debug);
    auto r = std::make_shared<hue::reader>(DIR);

    efsw::FileWatcher* watch = new efsw::FileWatcher();

    watch->watch();

    watch->addWatch(DIR, r.get());



    
    auto h = r->acquire();
    while(true) {
        std::pair<hue::game_state, event> item;
        // finite timeout, never infinite
        //spdlog::info("waiting for next event");
        bool ok = h->wait_dequeue_timed(item, std::chrono::milliseconds{ 100 });

        if(ok) {
            spdlog::info("event: {}", item.second.json().dump());
        }
    }
}