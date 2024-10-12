#pragma once


namespace changer {

enum Season {
  Winter = "Winter",
  Spring = "Spring",
  Summer = "Summer",
  Fall = "Fall"
};

Season get_season();

}

#ifdef _WIN32
#include <Windows.h>

namespace changer {


}

#endif