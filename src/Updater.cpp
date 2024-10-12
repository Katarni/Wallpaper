#include "../include/Updater.h"
#include <chrono>
#include <iostream>

changer::Season changer::get_season() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto local_time = *localtime(&time);

    auto month = local_time.tm_mon + 1;
    if (month <= 2 || month == 12) return Winter;
    if (month <= 5) return Spring;
    if (month <= 8) return Summer;
    return Fall;
}

