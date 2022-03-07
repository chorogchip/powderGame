#include "Game.h"


namespace ch {


Game* Game::static_instance_ = nullptr;

long long Game::getTicks() const {
	return game_ticks_;
}

sf::RenderWindow& Game::getWindow() {
	return game_window_;
}

bool Game::init() {
	if (!font_basic_.loadFromFile("resource/font/malgun.ttf")) {
		PRTLOG("error loading font: malgun.ttf");
		clear();
		return false;
	}
	if (!font_bold_.loadFromFile("resource/font/malgunbd.ttf")) {
		PRTLOG("error loading font: malgunbd.ttf");
		clear();
		return false;
	}
	if (!font_slim_.loadFromFile("resource/font/malgunsl.ttf")) {
		PRTLOG("error loading font: malgunsl.ttf");
		clear();
		return false;
	}
	texture_loader_.loadTexture();


	changeScene(new Scene_menu0_start());
	updateScene();

	return true;
}

void Game::run() {
	is_running_ = true;
	int timer;

	while (is_running_) {

		game_clock_.restart();

		handleEvents();
		update();
		render();
		updateScene();
		updateWorld();

		timer = game_clock_.getElapsedTime().asMilliseconds();

		if (timer < ch::UPDATE_DELAY) {
			Sleep(ch::UPDATE_DELAY - timer);
		}
	}

}

void Game::quit() {
	is_running_ = false;
}

void Game::clear() {

	if (world_ != nullptr) {
		delete world_;
		world_ = nullptr;
	}
	if (scene_ != nullptr) {
		delete scene_;
		scene_ = nullptr;
	}
	if (next_scene_ != nullptr) {
		delete next_scene_;
		next_scene_ = nullptr;
	}
	game_window_.close();


	if (static_instance_ != nullptr) {
		delete static_instance_;
		static_instance_ = nullptr;
	}


}

void Game::handleEvents() {
	game_event_handler_.handleEvent();
}

void Game::update() {
	if (is_in_world_) {
		world_->update();
	}
	scene_updater_.update(*scene_);
}

void Game::render() {

	game_window_.clear();

	if (is_in_world_) {
		world_renderer_.render(*world_);
	}
	scene_renderer_.render(*scene_);

	game_window_.display();

}

void Game::updateScene() {
	if (next_scene_ == nullptr) {
		return;
	} else {
		if (scene_ != nullptr) {
			delete scene_;
		}
		scene_ = next_scene_;
		next_scene_ = nullptr;
		scene_->guis_set_TransformedPos_N_Size(0, 0, this->getWindow().getSize().x, this->getWindow().getSize().y, this->getRenderstate().ui_scale);
	}
}

void Game::changeScene(Scene* scene) {
	if (next_scene_ != nullptr) {
		delete next_scene_;
	}
	next_scene_ = scene;
}

void Game::updateWorld() {
	if (next_world_ == nullptr) {
		return;
	} else {
		if (world_ != nullptr) {
			delete world_;
		}
		world_ = next_world_;
		next_world_ = nullptr;
		is_in_world_ = true;
	}
}

void Game::changeWorld(World* world) {
	if (next_world_ != nullptr) {
		delete next_world_;
	}
	next_world_ = world;
}


void Game::addGuiToScene(Gui* gui) {
	scene_->addGui(gui);
}

World& Game::getWorld() {
	return *world_;
}

RenderStates& Game::getRenderstate() {
	return render_state_;
}

TextureLoader& Game::getTextureLoader() {
	return texture_loader_;
}

sf::Font& Game::getFont(ch::EnumGameFonts font) {

	switch (font) {
	case ch::EnumGameFonts::BASIC: return font_basic_;
	case ch::EnumGameFonts::BOLD: return font_bold_;
	case ch::EnumGameFonts::SLIM: return font_slim_;
	default: return font_basic_;

	}
}


}