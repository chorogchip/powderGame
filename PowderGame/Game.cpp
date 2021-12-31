
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

	scene = new Scene0();
	//scale
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
		updateScene();

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

	if (scene != nullptr) {
		delete scene;
		scene = nullptr;
	}
	if (nextScene != nullptr) {
		delete nextScene;
		nextScene = nullptr;
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
		sceneEventHandler.handleEvents(*scene);
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
		sceneRenderer.render(*scene);
	} else {
		worldRenderer.render(*world);
	}

	gameWindow.display();

}


void Game::updateScene() {
	if (nextScene == nullptr) {
		return;
	} else {
		if (scene != nullptr) {
			delete scene;
		}
		scene = nextScene;
		nextScene = nullptr;
		//scale
	}
}

void Game::changeScene(Scene* scene) {
	if (nextScene != nullptr) {
		delete nextScene;
	}
	nextScene = scene;
}

World& Game::getWorld() {
	return *world;
}





SceneEventHandler& Game::getSceneEventHandler() {
	return sceneEventHandler;
}

WorldEventHandler& Game::getWorldEventHandler() {
	return worldEventHandler;
}

SceneRenderer&  Game::getSceneRenderer() {
	return sceneRenderer;
}

WorldRenderer&  Game::getWorldRenderer() {
	return worldRenderer;
}

RenderStates& Game::getRenderstate() {
	return renderstate;
}

void Game::initWorld(World* _world) {
	if (world != nullptr) {
		delete world;
	}
	world = _world;
}

sf::Font& Game::getFont(GameFonts font) {
	switch (font) {
	case GameFonts::BASIC: return font_basic;
	case GameFonts::BOLD: return font_bold;
	case GameFonts::SLIM: return font_slim;
	default: return font_basic;
	}
}