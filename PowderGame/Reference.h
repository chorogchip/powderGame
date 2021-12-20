#pragma once

#include <iostream>

#define prtLog(x) std::cout << x << std::endl

const int WINDOW_X = 1920;
const int WINDOW_Y = 1080;

const int FPS = 60;
const int UPDATE_DELAY = (1000 / FPS);
