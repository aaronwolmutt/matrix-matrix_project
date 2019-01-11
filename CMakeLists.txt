cmake_minimum_required(VERSION 3.0)

project(project1)

set (CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "src/*.cpp")
include_directories("lib/eigen")


add_executable(try ${SOURCES}) 

