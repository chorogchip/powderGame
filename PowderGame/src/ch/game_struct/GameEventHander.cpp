#include "GameEventHander.h"
#include "../main/Game.h"


namespace ch {


GameEventHander::GameEventHander() {

}

GameEventHander::~GameEventHander() {

}



void GameEventHander::handleEvent() {

	sf::Event evnt;
	ch::EnumActionResult res;
	while (Game::getInstance()->getWindow().pollEvent(evnt)) {
		int type = evnt.type;

		switch (type) {

		case sf::Event::Closed:
			Game::getInstance()->quit();
			return;

		default:
			continue;

		case sf::Event::GainedFocus:
			Game::getInstance()->game_options_.is_in_focus = true;
			continue;

		case sf::Event::LostFocus:
			Game::getInstance()->game_options_.is_in_focus = false;
			continue;

		case sf::Event::MouseEntered:
			Game::getInstance()->game_options_.is_mouse_inside = true;
			if (Game::getInstance()->game_options_.is_in_focus) {
				res = scene_event_handler_.onEvent_MouseEntered(*Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_MouseEntered(*Game::getInstance()->world_, res);
				}
			}
			continue;

		case sf::Event::MouseLeft:
			Game::getInstance()->game_options_.is_mouse_inside = false;
			if (Game::getInstance()->game_options_.is_in_focus) {
				res = scene_event_handler_.onEvent_MouseLeft(*Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_MouseLeft(*Game::getInstance()->world_, res);
				}
			}
			continue;

		case sf::Event::Resized:
			Game::getInstance()->getWindow().setView(sf::View(sf::FloatRect(0.0f, 0.0f, static_cast<float>(evnt.size.width), static_cast<float>(evnt.size.height))));
			Game::getInstance()->scene_->guis_set_TransformedPos_N_Size(0.0f, 0.0f, static_cast<float>(evnt.size.width), static_cast<float>(evnt.size.height), Game::getInstance()->getRenderstate().ui_scale);
			Game::getInstance()->game_options_.last_window_size = sf::Vector2i(evnt.size.width, evnt.size.height);
			continue;

		case sf::Event::TextEntered:
			if (Game::getInstance()->game_options_.is_in_focus) {
				res = scene_event_handler_.onEvent_TextEntered(evnt.text, *Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_TextEntered(evnt.text, *Game::getInstance()->world_, res);
				}
			}
			break;

		case sf::Event::KeyPressed:
			if (Game::getInstance()->game_options_.is_in_focus) {
				if (evnt.key.code == sf::Keyboard::Enter && (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))) {
					if (Game::getInstance()->game_options_.is_full_screen) {
						Game::getInstance()->getWindow().create(sf::VideoMode(Game::getInstance()->game_options_.last_window_size.x, Game::getInstance()->game_options_.last_window_size.y), L"게임", sf::Style::Default);
						Game::getInstance()->game_options_.is_full_screen = false;
					} else {
						Game::getInstance()->getWindow().create(sf::VideoMode::getFullscreenModes()[0], L"게임", sf::Style::Fullscreen);
						Game::getInstance()->game_options_.is_full_screen = true;
					}
					Game::getInstance()->getWindow().setView(sf::View(sf::FloatRect(0.0f, 0.0f,
																																					static_cast<float>(Game::getInstance()->getWindow().getSize().x),
																																					static_cast<float>(Game::getInstance()->getWindow().getSize().y))));
					Game::getInstance()->scene_->guis_set_TransformedPos_N_Size(0.0f, 0.0f,
																																			static_cast<float>(Game::getInstance()->getWindow().getSize().x),
																																			static_cast<float>(Game::getInstance()->getWindow().getSize().y),
																																			Game::getInstance()->getRenderstate().ui_scale);
					break;
				}
				res = scene_event_handler_.onEvent_KeyPressed(evnt.key, *Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_KeyPressed(evnt.key, *Game::getInstance()->world_, res);
				}
			}
			break;

		case sf::Event::KeyReleased:
			if (Game::getInstance()->game_options_.is_in_focus) {
				res = scene_event_handler_.onEvent_KeyReleased(evnt.key, *Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_KeyReleased(evnt.key, *Game::getInstance()->world_, res);
				}
			}
			break;

		case sf::Event::MouseWheelScrolled:
			if (Game::getInstance()->game_options_.is_in_focus) {
				res = scene_event_handler_.onEvent_MouseWheelScrolled(evnt.mouseWheelScroll, *Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_MouseWheelScrolled(evnt.mouseWheelScroll, *Game::getInstance()->world_, res);
				}
			}
			break;

		case sf::Event::MouseButtonPressed:
			if (Game::getInstance()->game_options_.is_in_focus) {
				res = scene_event_handler_.onEvent_MouseButtonPressed(evnt.mouseButton, *Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_MouseButtonPressed(evnt.mouseButton, *Game::getInstance()->world_, res);
				}
			}
			break;

		case sf::Event::MouseButtonReleased:
			if (Game::getInstance()->game_options_.is_in_focus) {
				res = scene_event_handler_.onEvent_MouseButtonReleased(evnt.mouseButton, *Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_MouseButtonReleased(evnt.mouseButton, *Game::getInstance()->world_, res);
				}
			}
			break;

		case sf::Event::MouseMoved:
			if (Game::getInstance()->game_options_.is_in_focus) {
				res = scene_event_handler_.onEvent_MouseMoved(evnt.mouseMove, *Game::getInstance()->scene_);
				if (ch::toSkip(res) && Game::getInstance()->is_in_world_) {
					world_event_handler_.onEvent_MouseMoved(evnt.mouseMove, *Game::getInstance()->world_, res);
				}
			}
			break;
		}
	}
}

}