cmake_minimum_required(VERSION 3.15)
project(glyphs LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS OFF)

set(RE2_BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(RE2_INSTALL OFF CACHE BOOL "" FORCE)

set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "" FORCE)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(PYBIND11_FINDPYTHON NEW)
add_subdirectory(extern/pybind11 EXCLUDE_FROM_ALL)
add_subdirectory(extern/efsw EXCLUDE_FROM_ALL)
add_subdirectory(extern/abseil-cpp EXCLUDE_FROM_ALL)
add_subdirectory(extern/re2 EXCLUDE_FROM_ALL)
add_subdirectory(extern/fmt EXCLUDE_FROM_ALL)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG        v1.16.0
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(json 
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)
FetchContent_MakeAvailable(json)

file(GLOB EVENT_SOURCE "src/events/*.cpp")

if(WIN32)
set(PLATFORM_SOURCE src/process_win32.cpp)
else()
set(PLATFORM_SOURCE src/process_linux.cpp)
endif()

add_library(events STATIC ${EVENT_SOURCE} "src/registry.cpp")
target_link_libraries(events PRIVATE nlohmann_json::nlohmann_json)

pybind11_add_module(_core MODULE src/python.cpp src/reader.cpp src/date/tz.cpp ${PLATFORM_SOURCE})
target_link_libraries(_core PUBLIC efsw events nlohmann_json::nlohmann_json spdlog::spdlog re2::re2 fmt::fmt)
target_include_directories(_core PRIVATE src/)
install(TARGETS _core DESTINATION glyphs)


add_executable(main src/main.cpp src/reader.cpp src/date/tz.cpp ${PLATFORM_SOURCE})
target_link_libraries(main PUBLIC efsw events nlohmann_json::nlohmann_json spdlog::spdlog re2::re2 fmt::fmt)
