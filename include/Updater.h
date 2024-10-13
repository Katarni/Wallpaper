#pragma once

#include <string>
#include <chrono>

#define Season std::wstring
#define Winter L"Winter"
#define Spring L"Spring"
#define Summer L"Summer"
#define Fall L"Fall"


namespace changer {

Season get_season();
// LEGACY
//class Timer {
//  public:
//    Timer() = default;
//    [[nodiscard]] bool passed() const;
//    void update();
//  private:
//    std::chrono::minutes last{std::chrono::system_clock::now().time_since_epoch() / std::chrono::minutes(1)};
//};


}


namespace changer {

bool change_wallpaper();


}

[[noreturn]] void circle();