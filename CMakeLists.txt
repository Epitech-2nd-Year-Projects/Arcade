cmake_minimum_required(VERSION 3.20)
project(arcade)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
  src/main.cpp
  src/Core/LibraryLoader.cpp
)

add_executable(arcade ${SOURCES})

target_include_directories(arcade PRIVATE src)
