#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Scene.h"
#include "World.h"
#include "SceneEventHandler.h"
#include "WorldEventHandler.h"
#include "SceneRenderer.h"
#include "WorldRenderer.h"
#include "Reference.h"
#include "RenderStates.h"
#include "EnumFonts.h"

class Game {
private:
	Game()
		:gameWindow(sf::VideoMode(1920, 1080), L"∞‘¿”", sf::Style::Close | sf::Style::Default | sf::Style::Resize),
		running(false), isInWorld(false), gameTicks(0L), renderstate(),
		scene(nullptr), nextScene(nullptr), world(nullptr) {};
	~Game() {};

	static Game* instance;
	sf::Clock gameClock;
	sf::RenderWindow gameWindow;
	sf::Font font_basic;
	sf::Font font_bold;
	sf::Font font_slim;
	bool running;
	long long gameTicks;

	Scene* scene;
	Scene* nextScene;
	World* world;
	bool isInWorld;

	SceneEventHandler sceneEventHandler;
	WorldEventHandler worldEventHandler;

	SceneRenderer sceneRenderer;
	WorldRenderer worldRenderer;

	RenderStates renderstate;

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
	void updateScene();
	void changeScene(Scene* menu);


	World& getWorld();

	SceneEventHandler& getSceneEventHandler();
	WorldEventHandler& getWorldEventHandler();

	SceneRenderer& getSceneRenderer();
	WorldRenderer& getWorldRenderer();

	RenderStates& getRenderstate();

	sf::Font& getFont(GameFonts font);


	void initWorld(World* world);
};

