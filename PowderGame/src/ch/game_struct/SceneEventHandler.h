#pragma once

#include <SFML/Graphics.hpp>

#include "../utils/EnumActionResult.h"

#include "../scene/Scene.h"

namespace ch {

class SceneEventHandler {
public:
	SceneEventHandler();
	~SceneEventHandler();
	SceneEventHandler (const SceneEventHandler&) = delete;
	SceneEventHandler& operator=(const SceneEventHandler&) = delete;

	ch::EnumActionResult onEvent_MouseEntered(Scene& scene);
	ch::EnumActionResult onEvent_MouseLeft(Scene& scene);
	ch::EnumActionResult onEvent_TextEntered(sf::Event::TextEvent& evnt, Scene& scene);
	ch::EnumActionResult onEvent_KeyPressed(sf::Event::KeyEvent& evnt, Scene& scene);
	ch::EnumActionResult onEvent_KeyReleased(sf::Event::KeyEvent& evnt, Scene& scene);
	ch::EnumActionResult onEvent_MouseWheelScrolled(sf::Event::MouseWheelScrollEvent& evnt, Scene& scene);
	ch::EnumActionResult onEvent_MouseButtonPressed(sf::Event::MouseButtonEvent& evnt, Scene& scene);
	ch::EnumActionResult onEvent_MouseButtonReleased(sf::Event::MouseButtonEvent& evnt, Scene& scene);
	ch::EnumActionResult onEvent_MouseMoved(sf::Event::MouseMoveEvent& evnt, Scene& scene);
};

}