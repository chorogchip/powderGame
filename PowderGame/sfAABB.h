#pragma once
#include "SFML/Graphics.hpp"

struct sfAABB {
	sf::Vector2f pos;
	sf::Vector2f size;

	sfAABB() :
		pos(sf::Vector2f(0.0f, 0.0f)), size(sf::Vector2f(0.0f, 0.0f)) {}

	sfAABB(sf::Vector2f _pos, sf::Vector2f _size) :
		pos(_pos), size(_size) {}

	sfAABB(const sfAABB& _aabb) :
		pos(_aabb.pos), size(_aabb.size) {}

};