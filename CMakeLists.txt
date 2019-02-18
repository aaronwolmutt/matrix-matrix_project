project(timings)
cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O3 -march=native")

include_directories("lib/eigen")

set(SOURCES
  ${PROJECT_SOURCE_DIR}/src/randommatrix.cpp
  ${PROJECT_SOURCE_DIR}/src/randomvector.cpp
  ${PROJECT_SOURCE_DIR}/src/timer.cpp
  ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(run ${SOURCES}) 

