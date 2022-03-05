#include "GameLauncher.h"

namespace ch {

int GameLauncher::launch() {

	if (Game::getInstance()->init()) {

		PRTLOG("Init succeed. Game is running");
		Game::getInstance()->run();

		PRTLOG("Game is closing");
		Game::getInstance()->clear();
		return 0;

	} else {

		PRTLOG("Game init failed.");
		return -1;

	}

}

}