#include "MenuEventHandler.h"
#include "Game.h"


MenuEventHandler::MenuEventHandler() {}


MenuEventHandler::~MenuEventHandler() {}


void MenuEventHandler::handleEvents() {
	sf::Event evnt;
	while (Game::getInstance()->getWindow().pollEvent(evnt)) {
		switch (evnt.type) {
		case sf::Event::Closed:
			Game::getInstance()->quit();
			break;

		case sf::Event::Resized:
			evnt.size.width;
			

			break;
		}
	}
}