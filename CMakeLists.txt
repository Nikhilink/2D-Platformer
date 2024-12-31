cmake_minimum_required(VERSION 3.12)
project(Platformer)

set(CMAAKE_CXX_STANDARD 23)

# Add the path to the Raylib package config file
list(APPEND CMAKE_PREFIX_PATH "raylib")

# Find the Raylib package
find_package(raylib 5.0 QUIET) # Let's find the installed raylib

# If Raylib is not installed on the system, fetch it and build from source
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/master.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

set(PCH_HEADER "src/pch.h")

# Define the executable
add_executable(${PROJECT_NAME} 
                src/main.cpp
                src/pch.h
                src/game.h
                src/game.cpp
                src/options.h
                src/logging.h
                src/log_utils.h
                src/log_utils.cpp
                src/managers.h
                src/managers.cpp
                src/scenes.h
                src/scenes.cpp
                src/loaders.h
                src/loaders.cpp
                src/game_objects.h
                src/game_objects.cpp
                src/tilemap.h
                src/tilemap.cpp
		)

target_precompile_headers(${PROJECT_NAME} PRIVATE ${PCH_HEADER})


# Link against raylib
target_link_libraries(${PROJECT_NAME} raylib)