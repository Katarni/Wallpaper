cmake_minimum_required(VERSION 3.28)
project(season_wallpaper)

set(CMAKE_CXX_STANDARD 26)

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS
            "-static -static-libgcc -static-libstdc++"
    )
endif(WIN32)


add_executable(season_wallpaper WIN32 src/main.cpp
        src/Updater.cpp
        include/Updater.h
        icon.rc)
