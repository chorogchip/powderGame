
#include "Game.h"

Game* Game::instance = nullptr;

long long Game::getTicks() const {
	return gameTicks;
}

sf::RenderWindow& Game::getWindow() {
	return gameWindow;
}

bool Game::init() {
	if (!font_basic.loadFromFile("resource/font/malgun.ttf")) {
		prtLog("error loading font: malgun.ttf");
		clear();
		return false;
	}
	if (!font_bold.loadFromFile("resource/font/malgunbd.ttf")) {
		prtLog("error loading font: malgunbd.ttf");
		clear();
		return false;
	}
	if (!font_slim.loadFromFile("resource/font/malgunsl.ttf")) {
		prtLog("error loading font: malgunsl.ttf");
		clear();
		return false;
	}


	menu = new Menu0();
	menu->updatePosNScale();
	return true;
}

void Game::run() {
	running = true;
	int timer;

	while (running) {

		gameClock.restart();

		handleEvents();
		update();
		render();
		updateMenu();

		timer = gameClock.getElapsedTime().asMilliseconds();

		if (timer < UPDATE_DELAY) {
			Sleep(UPDATE_DELAY - timer);
		}
	}
	
}

void Game::quit() {
	running = false;
}

void Game::clear() {

	if (menu != nullptr) {
		delete menu;
		menu = nullptr;
	}
	if (nextMenu != nullptr) {
		delete nextMenu;
		nextMenu = nullptr;
	}
	if (world != nullptr) {
		delete world;
		world = nullptr;
	}
	gameWindow.close();


	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}


}

void Game::handleEvents() {
	if (!isInWorld) {
		menuEventHandler.handleEvents(*menu);
	} else {
		worldEventHandler.handleEvents(*world);
	}
}

void Game::update() {
	if (!isInWorld) {

	} else {
		world->update();
	}
}

void Game::render() {

	gameWindow.clear();

	if (!isInWorld) {
		menuRenderer.render(*menu);
	} else {
		worldRenderer.render(*world);
	}

	gameWindow.display();

}


void Game::updateMenu() {
	if (nextMenu == nullptr) {
		return;
	} else {
		if (menu != nullptr) {
			delete menu;
		}
		menu = nextMenu;
		nextMenu = nullptr;
		menu->updatePosNScale();
	}
}

void Game::changeMenu(Menu* menu) {
	if (nextMenu != nullptr) {
		delete nextMenu;
	}
	nextMenu = menu;
}

World& Game::getWorld() {
	return *world;
}





MenuEventHandler& Game::getMenuEventHandler() {
	return menuEventHandler;
}

WorldEventHandler& Game::getWorldEventHandler() {
	return worldEventHandler;
}

MenuRenderer&  Game::getMenuRenderer() {
	return menuRenderer;
}

WorldRenderer&  Game::getWorldRenderer() {
	return worldRenderer;
}


void Game::initWorld(World* _world) {
	if (world != nullptr) {
		delete world;
	}
	world = _world;
}