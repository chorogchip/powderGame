#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Reference.h"

int main(int argc, char* args[])
{

	if (Game::getInstance()->init()) {

		prtLog("Init succeed. Game is running");
		Game::getInstance()->run();

		prtLog("Game is closing");
		Game::getInstance()->clear();
		
	} else {

		prtLog("Game init failed.");
		return -1;

	}

	return 0;
}
