#pragma once

// if windows.h is includes, need to first define NOMINMAX,
// so the header doesn't define min/max macros, destroying every usage of std::min/std::max.
#define NOMINMAX

#include <Windows.h>

#include <SFML/Graphics.hpp>

#include "Reference.h"
#include "EnumFonts.h"
#include "GameOptions.h"
#include "RenderStates.h"

#include "TextureLoader.h"
#include "Gui.h"
#include "Scene.h"
#include "SceneEventHandler.h"
#include "World.h"
#include "WorldEventHandler.h"
#include "GameEventHander.h"
#include "SceneRenderer.h"
#include "WorldRenderer.h"
#include "SceneUpdater.h"

#include "Scene_menu0_start.h"


namespace ch {


class Game {
private:
	Game()
		:game_window_(sf::VideoMode::getDesktopMode(), L"����", sf::Style::Default),
		is_running_(false), game_options_(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height),
		game_ticks_(0L), render_state_(),
		is_in_world_(false), scene_(nullptr), next_scene_(nullptr), world_(nullptr), next_world_(nullptr) { };
	~Game() { };

	static Game* static_instance_;

	sf::Clock game_clock_;
	sf::RenderWindow game_window_;
	bool is_running_;
	long long game_ticks_;

	Scene* scene_;
	Scene* next_scene_;
	World* world_;
	World* next_world_;
	bool is_in_world_;

	sf::Font font_basic_;
	sf::Font font_bold_;
	sf::Font font_slim_;

	GameEventHander game_event_handler_;

	SceneUpdater scene_updater_;

	SceneRenderer scene_renderer_;
	WorldRenderer world_renderer_;

	RenderStates render_state_;
	TextureLoader texture_loader_;

	bool init();
	void run();
	void clear();
	void handleEvents();
	void update();
	void render();
	void updateScene();
	void updateWorld();

public:
	static Game* getInstance() {
		if (static_instance_ == nullptr) {
			static_instance_ = new Game();
			return static_instance_;
		}
		return static_instance_;
	}

	ch::GameOptions game_options_;

	long long getTicks() const;
	sf::RenderWindow& getWindow();

	void quit();

	void addGuiToScene(Gui* gui);
	void changeScene(Scene* scene);
	void changeWorld(World* world);


	World& getWorld();

	RenderStates& getRenderstate();
	TextureLoader& getTextureLoader();

	sf::Font& getFont(ch::EnumGameFonts font);


	friend class GameLauncher;
	friend class GameEventHander;
};

}