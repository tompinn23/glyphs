#include "process.h"

#include <windows.h>
#include <sddl.h>
#include <aclapi.h>
#include <psapi.h>
#include <string>
#include <memory>

static std::wstring file_owner(const std::wstring &path) {
    PSECURITY_DESCRIPTOR sd = nullptr;
    PSID owner = nullptr;

    if (GetNamedSecurityInfoW(path.c_str(),
                              SE_FILE_OBJECT,
                              OWNER_SECURITY_INFORMATION,
                              &owner, nullptr, nullptr, nullptr,
                              &sd) != ERROR_SUCCESS)
        return L"";

    LPWSTR sidStr = nullptr;
    ConvertSidToStringSidW(owner, &sidStr);

    std::wstring out = sidStr ? sidStr : L"";
    if (sidStr) LocalFree(sidStr);
    if (sd) LocalFree(sd);
    return out;
}

static std::wstring self_owner() {
    HANDLE tok = nullptr;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &tok))
        return L"";

    DWORD size = 0;
    GetTokenInformation(tok, TokenUser, nullptr, 0, &size);
    if (!size) {
        CloseHandle(tok);
        return L"";
    }

    auto buf = std::make_unique<BYTE[]>(size);
    TOKEN_USER *usr = reinterpret_cast<TOKEN_USER*>(buf.get());

    std::wstring out;
    if (GetTokenInformation(tok, TokenUser, usr, size, &size)) {
        LPWSTR s = nullptr;
        if (ConvertSidToStringSidW(usr->User.Sid, &s)) {
            out = s;
            LocalFree(s);
        }
    }

    CloseHandle(tok);
    return out;
}

static std::wstring proc_owner(DWORD pid) {
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
    if (!h) return L"";

    HANDLE tok = nullptr;
    if (!OpenProcessToken(h, TOKEN_QUERY, &tok)) {
        CloseHandle(h);
        return L"";
    }

    DWORD size = 0;
    GetTokenInformation(tok, TokenUser, nullptr, 0, &size);
    if (!size) {
        CloseHandle(tok);
        CloseHandle(h);
        return L"";
    }

    auto buf = std::make_unique<BYTE[]>(size);
    TOKEN_USER *usr = reinterpret_cast<TOKEN_USER*>(buf.get());

    std::wstring out;
    if (GetTokenInformation(tok, TokenUser, usr, size, &size)) {
        LPWSTR s = nullptr;
        if (ConvertSidToStringSidW(usr->User.Sid, &s)) {
            out = s;
            LocalFree(s);
        }
    }

    CloseHandle(tok);
    CloseHandle(h);
    return out;
}

process::process(const std::string &journal_dir) {
    this->journal_dir = journal_dir;
}

bool process::running() {
    int wlen = MultiByteToWideChar(CP_UTF8, 0,
        journal_dir.c_str(), journal_dir.size(),
        nullptr, 0);
    std::wstring wjournal_dir(wlen, L'\0');
    MultiByteToWideChar(CP_UTF8, 0,
        journal_dir.c_str(), journal_dir.size(),
        wjournal_dir.data(), wlen);
    std::wstring dirSid  = file_owner(wjournal_dir);
    std::wstring selfSid = self_owner();

    if (pid) {
        HANDLE h = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, *pid);
        if (h) {
            DWORD ec = 0;
            if (GetExitCodeProcess(h, &ec) && ec == STILL_ACTIVE) {
                CloseHandle(h);
                return true;
            }
            CloseHandle(h);
        }
        pid.reset();
    }

    DWORD pids[4096];
    DWORD needed = 0;

    if (!EnumProcesses(pids, sizeof(pids), &needed))
        return false;

    DWORD count = needed / sizeof(DWORD);

    for (DWORD i = 0; i < count; i++) {
        DWORD pidCandidate = pids[i];
        if (!pidCandidate) continue;

        HANDLE h = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION | PROCESS_VM_READ, FALSE, pidCandidate);
        if (!h) continue;

        WCHAR name[260];
        DWORD size = sizeof(name);
        if (!QueryFullProcessImageNameW(h, 0, name, &size)) {
            CloseHandle(h);
            continue;
        }

        const WCHAR *base = wcsrchr(name, L'\\');
        base = base ? base + 1 : name;

        if (wcsstr(base, L"EliteDangerous")) {
            std::wstring psid = proc_owner(pidCandidate);
            CloseHandle(h);

            if (psid == dirSid || psid == selfSid) {
                pid = pidCandidate;
                return true;
            }
        } else {
            CloseHandle(h);
        }
    }

    return false;
}