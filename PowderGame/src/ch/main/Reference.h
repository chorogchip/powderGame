#pragma once

#include <iostream>

#define PRTLOG(x) std::cout << x << std::endl

namespace ch {
  constexpr int FPS = 60;
  constexpr int UPDATE_DELAY = (1000 / FPS);
}
 