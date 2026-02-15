#include "process.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <signal.h>
#include <string>
#include <optional>
#include <cerrno>
#include <cstring>


static std::string file_owner(const std::string& path) {
    struct stat st;
    if (stat(path.c_str(), &st) != 0)
        return {};
    return std::to_string(st.st_uid);
}

static std::string self_owner() {
    uid_t u = getuid();
    return std::to_string(u);
}

static std::string proc_owner(pid_t pid) {
    struct stat st;
    std::string procPath = "/proc/" + std::to_string(pid);
    if (stat(procPath.c_str(), &st) != 0)
        return {};
    return std::to_string(st.st_uid);
}

process::process(const std::string& journal_dir) {
    this->journal_dir = journal_dir;
}

bool process::running() {
    std::string dirUid = file_owner(journal_dir);
    std::string selfUid = self_owner();

    if (pid) {
        if (kill(*pid, 0) == 0)
            return true;
		pid = std::nullopt;
    }

    DIR* d = opendir("/proc");
    if (!d)
        return false;

    struct dirent* ent;
    while ((ent = readdir(d)) != nullptr) {
        if (ent->d_type != DT_DIR && ent->d_type != DT_LNK && ent->d_type != DT_UNKNOWN)
            continue;

        char* end = nullptr;
        long v = strtol(ent->d_name, &end, 10);
        if (!ent->d_name[0] || *end != '\0')
            continue;
        if (v <= 0)
            continue;

        pid_t pidCandidate = static_cast<pid_t>(v);

        std::string exeLink = "/proc/" + std::to_string(pidCandidate) + "/exe";
        char buf[PATH_MAX];
        ssize_t len = readlink(exeLink.c_str(), buf, sizeof(buf) - 1);
        if (len < 0)
            continue;

        buf[len] = '\0';
        const char* base = strrchr(buf, '/');
        base = base ? base + 1 : buf;

        if (strstr(base, "EliteDangerous")) {
            std::string psid = proc_owner(pidCandidate);
            if (psid == dirUid || psid == selfUid) {
                closedir(d);
                pid = pidCandidate;
                return true;
            }
        }
    }

    closedir(d);
    return false;
}
