#pragma once

#include <SFML/Graphics.hpp>

namespace ch {

	struct sfAABB {
		sf::Vector2f pos;
		sf::Vector2f size;

		sfAABB() :
			pos(sf::Vector2f(0.0f, 0.0f)), size(sf::Vector2f(0.0f, 0.0f)) {}

		sfAABB(sf::Vector2f pos_in, sf::Vector2f size_in) :
			pos(pos_in), size(size_in) {}
		
		sfAABB(const sfAABB& aabb_in) :
			pos(aabb_in.pos), size(aabb_in.size) {}
	};

	struct AABB {
		int x, y, w, h;
	
		AABB(int xPos, int yPos, int width, int height) :
			x(xPos), y(yPos), w(width), h(height) {}
	};

	inline constexpr bool isInAABB_Closed(int pointX, int pointY, int posX, int posY, int width, int height) {
		return ((pointX > posX) && (pointX < (posX + width)) && (pointY > posY) && (pointY < (posY + height)));
	}
	inline constexpr bool isInAABB_HalfOpened(int pointX, int pointY, int posX, int posY, int width, int height) {
		return ((pointX >= posX) && (pointX < (posX + width)) && (pointY >= posY) && (pointY < (posY + height)));
	}
	inline bool isInAABB_HalfOpened(int pointX, int pointY, const sfAABB rect) {
		return ((pointX >= rect.pos.x) && (pointX < (rect.pos.x + rect.size.x)) && (pointY >= rect.pos.y) && (pointY < (rect.pos.y + rect.size.y)));
	}
	inline constexpr bool isInAABB_Opened(int pointX, int pointY, int posX, int posY, int width, int height) {
		return ((pointX >= posX) && (pointX <= (posX + width)) && (pointY >= posY) && (pointY <= (posY + height)));
	}
}