#pragma once

#include <SFML/Graphics.hpp>

#include "../../main/Reference.h"

struct RenderStates {

	RenderStates(float ui__scale = 1.0f, float cam__zoom = 1.0f, sf::Vector2f cam__pos = sf::Vector2f(0.0f, 0.0f))
	:ui_scale(ui__scale), cam_zoom(cam__zoom), cam_pos(cam__pos) {

	}

	float ui_scale;
	float cam_zoom;
	sf::Vector2f cam_pos;
};