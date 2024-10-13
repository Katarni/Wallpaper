cmake_minimum_required(VERSION 3.29)
project(season_wallpaper)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_EXE_LINKER_FLAGS
        "-static -static-libgcc -static-libstdc++"
)

add_executable(season_wallpaper WIN32 src/main.cpp
        src/Updater.cpp
        include/Updater.h
        icon.rc)
