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

set(LIB_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

file(MAKE_DIRECTORY ${LIB_OUTPUT_DIR})

set(SDL2_LIB_SOURCES
        src/Graphics/sdl2/sdl2.cpp
        src/Graphics/sdl2/ResourceManager.cpp
        src/Shared/Resource/ResourceIdentifier.cpp
        src/Shared/Resource/ResourceRegistry.cpp
        src/Shared/Scene/Drawable.cpp
)

add_library(arcade_sdl2 SHARED ${SDL2_LIB_SOURCES})
