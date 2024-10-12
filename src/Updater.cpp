#include "../include/Updater.h"
#include <filesystem>
#include <vector>
#include <random>
#include <iostream>

using namespace std::chrono_literals;

Season changer::get_season() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto local_time = *localtime(&time);

    auto month = local_time.tm_mon + 1;
    if (month <= 2 || month == 12) return Winter;
    if (month <= 5) return Spring;
    if (month <= 8) return Summer;
    return Fall;
}

bool changer::Timer::passed() const {
    std::chrono::minutes now(std::chrono::system_clock::now().time_since_epoch() / std::chrono::minutes(1));
    return now - last >= 1min;
}

void changer::Timer::update() {
    std::chrono::minutes now(std::chrono::system_clock::now().time_since_epoch() / std::chrono::minutes(1));
    last = now;
}

#ifdef _WIN32
#include <Windows.h>

bool changer::change_wallpaper() {
    static const std::wstring current = std::filesystem::current_path().wstring();
    static std::random_device dev;
    static std::mt19937 generator(dev());
    std::wstring season = current + std::wstring(L"/../Seasons/") + get_season();

    std::vector<std::wstring> variants;

    for (auto& i : std::filesystem::directory_iterator(season)) {
        variants.push_back(i.path().wstring());
    }

    auto wallpaper = variants[generator() % variants.size()];

    return SystemParametersInfoW(
            SPI_SETDESKWALLPAPER,
            0,
            (PVOID)wallpaper.c_str(),
            SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
    );
}

#endif


[[noreturn]] void circle() {
    changer::Timer t;
    while (true) {
        if (t.passed()) {
            std::cout << "NOW" << std::endl;
            t.update();
            changer::change_wallpaper();
        }
    }
}