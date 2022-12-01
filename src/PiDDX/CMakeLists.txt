cmake_minimum_required(VERSION 3.5)

project(PiDDX-Renderer)

add_library(piddx-renderer renderer.cpp renderer.h)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})
target_link_libraries(piddx-renderer ${PNG_LIBRARY})
