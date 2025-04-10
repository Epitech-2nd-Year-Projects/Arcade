cmake_minimum_required(VERSION 3.20)
project(arcade)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-gnu-unique")

# Core Sources
set(CORE_SOURCES
        src/main.cpp
        src/Core/LibraryLoader.cpp
        src/Shared/Resource/ResourceIdentifier.cpp
        src/Shared/Resource/ResourceRegistry.cpp
        src/Shared/Scene/Drawable.cpp
        src/Shared/GameView.cpp
        src/Shared/Scene/GameScene.cpp
        src/Shared/GameEvent.cpp
)

# SDL2 Sources
set(SDL2_LIB_SOURCES
        src/Graphics/sdl2/sdl2.cpp
        src/Graphics/sdl2/ResourceManager.cpp
)

# NCurse Sources
set(NCURSES_LIB_SOURCES
)

# SFML Sources
set(SFML_LIB_SOURCES
)

# Snake Sources
set(SNAKE_LIB_SOURCES
)

# MineSweeper Sources
set(MINESWEEPER_LIB_SOURCES
)

add_executable(arcade ${CORE_SOURCES})
target_include_directories(arcade PRIVATE src)
target_link_libraries(arcade PRIVATE dl)

set(LIB_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
file(MAKE_DIRECTORY ${LIB_OUTPUT_DIR})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR})

# SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
add_library(arcade_sdl2 SHARED ${SDL2_LIB_SOURCES})
target_include_directories(arcade_sdl2 PRIVATE src)
target_link_libraries(arcade_sdl2 PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)

# NCurses
find_package(Curses REQUIRED)
add_library(arcade_ncurses SHARED ${NCURSES_LIB_SOURCES})
target_include_directories(arcade_ncurses PRIVATE src)
target_link_libraries(arcade_ncurses PRIVATE ${CURSES_LIBRARIES})

# SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_library(arcade_sfml SHARED ${SFML_LIB_SOURCES})
target_include_directories(arcade_sfml PRIVATE src)
target_link_libraries(arcade_sfml PRIVATE sfml-graphics sfml-window sfml-system)

# Snake
add_library(arcade_snake SHARED ${SNAKE_LIB_SOURCES})
target_include_directories(arcade_snake PRIVATE src)

# MineSweeper
add_library(arcade_minesweeper SHARED ${MINESWEEPER_LIB_SOURCES})
target_include_directories(arcade_minesweeper PRIVATE src)


add_custom_target(core DEPENDS arcade)
add_custom_target(games DEPENDS arcade_snake arcade_minesweeper)
add_custom_target(graphicals DEPENDS arcade_sdl2 arcade_ncurses arcade_sfml)

add_custom_target(fclean
        COMMAND ${CMAKE_COMMAND} --build . --target clean
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${LIB_OUTPUT_DIR}
        COMMAND ${CMAKE_COMMAND} -E remove -f arcade
)

add_custom_target(re
        COMMAND ${CMAKE_COMMAND} --build . --target fclean
        COMMAND ${CMAKE_COMMAND} --build . --target all
)