#pragma once

#include <string>
#define Season std::wstring
#define Winter L"Winter"
#define Spring L"Spring"
#define Summer L"Summer"
#define Fall L"Fall"


namespace changer {

Season get_season();

}

#ifdef _WIN32
#include <Windows.h>

namespace changer {


}

#endif