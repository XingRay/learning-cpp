cmake_minimum_required(VERSION 3.28)
project(001_helloworld)
add_compile_options(-finput-charset=UTF-8)

# https://lvv.me/posts/2022/05/14_visual_studio_cmake_using_utf8/
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall /utf-8")
set(CMAKE_CXX_STANDARD 23)
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
file(GLOB source_files "${source_dir}/*.cpp")

include_directories(
        src
)

add_executable(001_helloworld ${source_files})
