#include "SceneEventHandler.h"
#include "Game.h"


SceneEventHandler::SceneEventHandler() {}


SceneEventHandler::~SceneEventHandler() {}


void SceneEventHandler::handleEvents(Scene& Scene) {
	sf::Event evnt;
	while (Game::getInstance()->getWindow().pollEvent(evnt)) {

		switch (evnt.type) {

		case sf::Event::Closed:
			Game::getInstance()->quit();
			break;

		case sf::Event::Resized:
			//Game::getInstance()->renderstate.windowX = evnt.size.width;
			//Game::getInstance()->renderstate.windowY = evnt.size.height;
			//updateposNscale
			break;
		}
	}
}