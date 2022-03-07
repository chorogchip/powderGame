#pragma once

#include <SFML/Graphics.hpp>

#include "../utils/EnumActionResult.h"

#include "../world/World.h"


namespace ch {

class WorldEventHandler {
public:
	WorldEventHandler();
	~WorldEventHandler();

	ch::EnumActionResult onEvent_MouseEntered(World& scene, ch::EnumActionResult prev);
	ch::EnumActionResult onEvent_MouseLeft(World& scene, ch::EnumActionResult prev);
	ch::EnumActionResult onEvent_TextEntered(sf::Event::TextEvent& evnt, World& world, ch::EnumActionResult prev);
	ch::EnumActionResult onEvent_KeyPressed(sf::Event::KeyEvent& evnt, World& world, ch::EnumActionResult prev);
	ch::EnumActionResult onEvent_KeyReleased(sf::Event::KeyEvent& evnt, World& world, ch::EnumActionResult prev);
	ch::EnumActionResult onEvent_MouseWheelScrolled(sf::Event::MouseWheelScrollEvent& evnt, World& world, ch::EnumActionResult prev);
	ch::EnumActionResult onEvent_MouseButtonPressed(sf::Event::MouseButtonEvent& evnt, World& world, ch::EnumActionResult prev);
	ch::EnumActionResult onEvent_MouseButtonReleased(sf::Event::MouseButtonEvent& evnt, World& world, ch::EnumActionResult prev);
	ch::EnumActionResult onEvent_MouseMoved(sf::Event::MouseMoveEvent& evnt, World& world, ch::EnumActionResult prev);
};

}