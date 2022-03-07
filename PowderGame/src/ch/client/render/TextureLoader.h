#pragma once

#include <string>
#include <array>

#include <SFML/Graphics.hpp>

#include "../../main/Reference.h"


namespace ch {


constexpr int TEXTURES_BUTTON_X = 20;
constexpr int TEXTURES_BUTTON_Y = 20;

constexpr int TEXTURES_BAR_X = 16;
constexpr int TEXTURES_BAR_Y = 3;

class TextureLoader {

public:
	TextureLoader();
	~TextureLoader();

	void loadTexture();

	void setTexture_Button(sf::Sprite& s0, sf::Sprite& s1, sf::Sprite& s2, int wdx, int wdy);
	void setTexture_Bar(sf::Sprite& bar0, sf::Sprite& bar1, sf::Sprite& bar2, sf::Sprite& h0, sf::Sprite& h1, sf::Sprite& h2, int wdx, int wdy);
	void setTexture_Movebar(sf::Sprite& s0, sf::Sprite& s1, sf::Sprite& s2, int wdx, int wdy);


private:

	inline void lodT(sf::Texture& texture, std::string str);

	sf::Texture tex_;
	sf::Sprite spr_;
	std::array<std::array<std::pair<bool, std::array<sf::RenderTexture*, 3>>, TEXTURES_BUTTON_Y>, TEXTURES_BUTTON_X> textures_button_;
	std::array<std::array<std::pair<bool, std::array<sf::RenderTexture*, 3>>, TEXTURES_BAR_Y>, TEXTURES_BAR_X> textures_bar_;
	std::array<std::pair<bool, std::array<sf::RenderTexture*, 3>>, TEXTURES_BUTTON_Y> textures_bar_handle_;
	std::array<sf::RenderTexture, 3> textures_movebar_;
	void initializeTexture_Button(int wdx, int wdy);
	void initializeTexture_Bar(int wdx, int wdy);
	void initializeTexture_Movebar();

};


}