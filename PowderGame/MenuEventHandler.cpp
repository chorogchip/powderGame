#include "MenuEventHandler.h"
#include "Game.h"


MenuEventHandler::MenuEventHandler() {}


MenuEventHandler::~MenuEventHandler() {}


void MenuEventHandler::handleEvents(Menu& menu) {
	sf::Event evnt;
	while (Game::getInstance()->getWindow().pollEvent(evnt)) {

		switch (evnt.type) {

		case sf::Event::Closed:
			Game::getInstance()->quit();
			break;

		case sf::Event::Resized:
			//Game::getInstance()->renderstate.windowX = evnt.size.width;
			//Game::getInstance()->renderstate.windowY = evnt.size.height;
			menu.updatePosNScale();
			break;
		}
	}
}