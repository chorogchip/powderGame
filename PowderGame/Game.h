#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Menu.h"
#include "Menu0.h"
#include "World.h"
#include "MenuEventHandler.h"
#include "WorldEventHandler.h"
#include "MenuRenderer.h"
#include "WorldRenderer.h"
#include "Reference.h"
#include "RenderStates.h"

class Game {
private:
	Game()
		:gameWindow(sf::VideoMode(1920, 1080), L"∞‘¿”", sf::Style::Close | sf::Style::Default | sf::Style::Resize),
		running(false), isInWorld(false), gameTicks(0L), renderstate(),
		menu(nullptr), nextMenu(nullptr), world(nullptr) {};
	~Game() {};

	static Game* instance;
	sf::Clock gameClock;
	sf::RenderWindow gameWindow;
	sf::Font font_basic;
	sf::Font font_bold;
	sf::Font font_slim;
	bool running;
	long long gameTicks;

	Menu* menu;
	Menu* nextMenu;
	World* world;
	bool isInWorld;

	MenuEventHandler menuEventHandler;
	WorldEventHandler worldEventHandler;

	MenuRenderer menuRenderer;
	WorldRenderer worldRenderer;


public:
	static Game* getInstance() {
		if (instance == nullptr) {
			instance = new Game();
			return instance;
		}
		return instance;
	}
	
	long long getTicks() const;
	sf::RenderWindow& getWindow();

	bool init();
	void run();
	void quit();
	void clear();

	void handleEvents();
	void update();
	void render();
	void updateMenu();
	void changeMenu(Menu* menu);


	World& getWorld();

	MenuEventHandler& getMenuEventHandler();
	WorldEventHandler& getWorldEventHandler();

	MenuRenderer& getMenuRenderer();
	WorldRenderer& getWorldRenderer();

	RenderStates renderstate;


	void initWorld(World* world);
};

