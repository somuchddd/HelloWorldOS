cmake_minimum_required(VERSION 3.16)

project(ProcessLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(ProcessLibrary STATIC src/process.cpp)

target_include_directories(ProcessLibrary PUBLIC include)

add_executable(ProcessTest src/main.cpp)
target_link_libraries(ProcessTest PRIVATE ProcessLibrary)

add_executable(child src/child.cpp)