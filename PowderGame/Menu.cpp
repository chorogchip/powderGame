#include "Menu.h"
#include "Game.h"


Menu::Menu() {
}


Menu::~Menu() {}

void Menu::updatePosNScale() {
	sf::RenderWindow& window = Game::getInstance()->getWindow();
	int wdx = window.getSize().x;
	int wdy = window.getSize().y;
	float sc = Game::getInstance()->renderstate.uiScale;


	for (auto &o : buttons) {

		float xG = sc * o.xGap;
		float yG = sc * o.yGap;
		float wid = sc * o.width;
		float hei = sc * o.height;

		switch (o.side) {

		case EnumSides::TOP_LEFT:		o.aabb.pos = sf::Vector2f(                    xG, yG);							break;
		case EnumSides::TOP_MIDDLE:		o.aabb.pos = sf::Vector2f(((wdx - wid) / 2) + xG, yG);							break;
		case EnumSides::TOP_RIGHT:		o.aabb.pos = sf::Vector2f(        wdx - wid + xG, yG);							break;
		case EnumSides::MIDDLE_LEFT:	o.aabb.pos = sf::Vector2f(                    xG, ((wdy - hei) / 2) + yG);		break;
		case EnumSides::MIDDLE_MIDDLE:	o.aabb.pos = sf::Vector2f(((wdx - wid) / 2) + xG, ((wdy - hei) / 2) + yG);		break;
		case EnumSides::MIDDLE_RIGHT:	o.aabb.pos = sf::Vector2f(        wdx - wid + xG, ((wdy - hei) / 2) + yG);		break;
		case EnumSides::BOTTOM_LEFT:	o.aabb.pos = sf::Vector2f(                    xG, wdy - hei + yG);				break;
		case EnumSides::BOTTOM_MIDDLE:	o.aabb.pos = sf::Vector2f(((wdx - wid) / 2) + xG, wdy - hei + yG);				break;
		case EnumSides::BOTTOM_RIGHT:	o.aabb.pos = sf::Vector2f(        wdx - wid + xG, wdy - hei + yG);				break;

		default: continue;
		}
		o.aabb.size = sf::Vector2f(wid, hei);
		o.sprite.setPosition(o.aabb.pos);
		o.sprite.setScale(sf::Vector2f(sc, sc));
	}
}