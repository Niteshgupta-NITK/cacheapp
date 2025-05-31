cmake_minimum_required(VERSION 3.14)
project(cacheapp)

set(CMAKE_CXX_STANDARD 17)

# Include directory for headers
include_directories(include)

# Add source files
add_executable(cache_app
    src/main.cpp
    src/cache.cpp
    src/server.cpp
    src/networking/tcp_server.cpp
)

# Optionally add test target
enable_testing()
add_subdirectory(tests)
