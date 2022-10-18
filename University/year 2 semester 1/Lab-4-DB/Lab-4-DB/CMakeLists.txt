cmake_minimum_required(VERSION 3.22)
project(Lab_4_DB)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_4_DB main.cpp)
#include_directories(/usr/include)
#link_directories(/usr/lib)

find_package(SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(Lab_4_DB SQLite::SQLite3)