cmake_minimum_required(VERSION 3.28)
project(001_helloworld)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
#set(CMAKE_CXX_STANDARD 23)
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
file(GLOB source_files "${source_dir}/*.cpp")

add_executable(001_helloworld ${source_files})
