#include "TextureLoader.h"


namespace ch {


TextureLoader::TextureLoader() { }

TextureLoader::~TextureLoader() {
	for (auto& o1 : textures_button_) {
		for (auto& o2 : o1) {
			if (o2.first) {
				delete o2.second[0];
				delete o2.second[1];
				delete o2.second[2];
			}
		}
	}
	for (auto& o1 : textures_bar_) {
		for (auto& o2 : o1) {
			if (o2.first) {
				delete o2.second[0];
				delete o2.second[1];
				delete o2.second[2];
			}
		}
	}
	for (auto& o1 : textures_bar_handle_) {
		if (o1.first) {
			delete o1.second[0];
			delete o1.second[1];
			delete o1.second[2];
		}
	}
}

void TextureLoader::loadTexture() {

	lodT(tex_, "resource/texture/gui/Sprite-0001-buttons.png");
	spr_.setTexture(tex_);

	initializeTexture_Button(16, 16);
	initializeTexture_Button(16, 32);
	initializeTexture_Button(48, 16);
	initializeTexture_Button(48, 48);
	initializeTexture_Button(256, 32);
	initializeTexture_Button(256, 64);

	initializeTexture_Bar(128, 64);

	initializeTexture_Movebar();

	initializeTexture_GameOverlay_Btn();

	initializeTexture_other();
}


inline void TextureLoader::lodT(sf::Texture& texture, std::string str) {
	if (!texture.loadFromFile(str)) {
		PRTLOG("error loading texture: " + str);
	}
}


void TextureLoader::setTexture_Button(sf::Sprite& s0, sf::Sprite& s1, sf::Sprite& s2, int wdx, int wdy) {
#ifdef _DEBUG
	if (wdx <= 0 || wdy <= 0) {
		throw "wdx and wdy must be positive.";
	}
	if ((wdx & 0b111) != 0) {
		throw "wdx should be 16 times N.";
	}
	if ((wdy & 0b111) != 0) {
		throw "wdy should be 16 times N.";
	}
	if ((wdx >> 4) > TEXTURES_BUTTON_X) {
		throw "wdx is too big.";
	}
	if ((wdy >> 4) > TEXTURES_BUTTON_Y) {
		throw "wdy is too big.";
	}
	if (!textures_button_.at((wdx >> 4) - 1).at((wdy >> 4) - 1).first) {
		throw "button render_texture not initialized.";
	}
#endif
	sf::RenderTexture** rtx = &textures_button_.at((wdx >> 4) - 1).at((wdy >> 4) - 1).second[0];
	s0.setTexture(rtx[0]->getTexture());
	s1.setTexture(rtx[1]->getTexture());
	s2.setTexture(rtx[2]->getTexture());
}

void TextureLoader::setTexture_Bar(sf::Sprite& bar0, sf::Sprite& bar1, sf::Sprite& bar2, sf::Sprite& h0, sf::Sprite& h1, sf::Sprite& h2, int wdx, int wdy) {
	int xdy = wdx / wdy;
#ifdef _DEBUG
	if (wdx <= 0 || wdy <= 0) {
		throw "wdx and wdy must be positive.";
	}
	if ((wdy & 0b111) != 0) {
		throw "wdy should be 16 times N.";
	}
	if ((wdx % wdy) != 0) {
		throw "wdx should be wdy times N.";
	}
	if (xdy > TEXTURES_BAR_X) {
		throw "wdx is too big.";
	}
	if ((wdy >> 4) > TEXTURES_BAR_X) {
		throw "wdy is too big.";
	}
	if (!textures_bar_.at(xdy - 1).at((wdy >> 4) - 1).first) {
		throw "button render_texture not initialized.";
	}
	if (!textures_bar_handle_.at((wdy >> 4) - 1).first) {
		throw "button render_texture not initialized.";
	}
#endif
	sf::RenderTexture** rtx = &textures_bar_.at(xdy - 1).at((wdy >> 4) - 1).second[0];
	bar0.setTexture(rtx[0]->getTexture());
	bar1.setTexture(rtx[1]->getTexture());
	bar2.setTexture(rtx[2]->getTexture());
	sf::RenderTexture** rtxh = &textures_bar_handle_.at((wdy >> 4) - 1).second[0];
	h0.setTexture(rtxh[0]->getTexture());
	h1.setTexture(rtxh[1]->getTexture());
	h2.setTexture(rtxh[2]->getTexture());
}

void TextureLoader::setTexture_Movebar(sf::Sprite& s0, sf::Sprite& s1, sf::Sprite& s2, int wdx, int wdy) {
	s0.setTexture(textures_movebar_[0].getTexture());
	s1.setTexture(textures_movebar_[1].getTexture());
	s2.setTexture(textures_movebar_[2].getTexture());
	s0.setTextureRect(sf::IntRect(0, 0, wdx, wdy));
	s1.setTextureRect(sf::IntRect(0, 0, wdx, wdy));
	s2.setTextureRect(sf::IntRect(0, 0, wdx, wdy));
}

const sf::Texture& TextureLoader::getTexture_GameOverlay_Btn(int index) const {
	return textures_gameoverlay_btn_[index].getTexture();
}

const sf::Texture& TextureLoader::getTexture_select() const {
	return texture_selection_.getTexture();
}





















void TextureLoader::initializeTexture_Button(int wdx, int wdy) {
#ifdef _DEBUG
	if (wdx <= 0 || wdy <= 0) {
		throw "wdx and wdy must be positive.";
	}
	if ((wdx & 0b111) != 0) {
		throw "wdx should be 16 times N.";
	}
	if ((wdy & 0b111) != 0) {
		throw "wdy should be 16 times N.";
	}
	if ((wdx >> 4) > TEXTURES_BUTTON_X) {
		throw "wdx is too big.";
	}
	if ((wdy >> 4) > TEXTURES_BUTTON_Y) {
		throw "wdy is too big.";
	}
	if (textures_button_.at((wdx >> 4) - 1).at((wdy >> 4) - 1).first) {
		throw "button render_texture already initialized.";
	}
#endif
	sf::RenderTexture** rtx = &textures_button_.at((wdx >> 4) - 1).at((wdy >> 4) - 1).second[0];
	sf::RenderTexture* rt0 = new sf::RenderTexture;
	sf::RenderTexture* rt1 = new sf::RenderTexture;
	sf::RenderTexture* rt2 = new sf::RenderTexture;
	rt0->create(wdx, wdy);
	rt1->create(wdx, wdy);
	rt2->create(wdx, wdy);
	
	if (wdx == 16) {
		if (wdy == 16) {
			spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
			spr_.setTextureRect(sf::IntRect(0, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(0, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(0, 32, 16, 16));
			rt2->draw(spr_);
		} else {
			int middle = (wdy - 16) >> 4;
			spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
			spr_.setTextureRect(sf::IntRect(64, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(64, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(64, 32, 16, 16));
			rt2->draw(spr_);

			spr_.setTextureRect(sf::IntRect(80, 0, 16, 16));
			for (int i = 1; i != middle; i++) {
				spr_.setPosition(sf::Vector2f(0.0f, static_cast<float>(i * 16)));
				rt0->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(80, 16, 16, 16));
			for (int i = 1; i != middle; i++) {
				spr_.setPosition(sf::Vector2f(0.0f, static_cast<float>(i * 16)));
				rt1->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(80, 32, 16, 16));
			for (int i = 1; i != middle; i++) {
				spr_.setPosition(sf::Vector2f(0.0f, static_cast<float>(i * 16)));
				rt2->draw(spr_);
			}

			spr_.setPosition(sf::Vector2f(0.0f, static_cast<float>(wdy - 16)));
			spr_.setTextureRect(sf::IntRect(96, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(96, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(96, 32, 16, 16));
			rt2->draw(spr_);
		}
	} else {
		if (wdy == 16) {
			int middle = (wdx - 16) >> 4;
			spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
			spr_.setTextureRect(sf::IntRect(16, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(16, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(16, 32, 16, 16));
			rt2->draw(spr_);

			spr_.setTextureRect(sf::IntRect(32, 0, 16, 16));
			for (int i = 1; i != middle; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i * 16), 0.0f));
				rt0->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(32, 16, 16, 16));
			for (int i = 1; i != middle; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i * 16), 0.0f));
				rt1->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(32, 32, 16, 16));
			for (int i = 1; i != middle; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i * 16), 0.0f));
				rt2->draw(spr_);
			}

			spr_.setPosition(sf::Vector2f(static_cast<float>(wdx - 16), 0.0f));
			spr_.setTextureRect(sf::IntRect(48, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(48, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(48, 32, 16, 16));
			rt2->draw(spr_);
		} else {
			int middle_X = (wdx - 16) >> 4;
			int middle_Y = (wdy - 16) >> 4;
			spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
			spr_.setTextureRect(sf::IntRect(112, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(112, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(112, 32, 16, 16));
			rt2->draw(spr_);
			spr_.setPosition(sf::Vector2f(static_cast<float>(wdx - 16), 0.0f));
			spr_.setTextureRect(sf::IntRect(128, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(128, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(128, 32, 16, 16));
			rt2->draw(spr_);

			spr_.setTextureRect(sf::IntRect(176, 0, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), 0.0f));
				rt0->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(176, 16, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), 0.0f));
				rt1->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(176, 32, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), 0.0f));
				rt2->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(192, 0, 16, 16));
			for (int i = 1; i != middle_Y; i++) {
				spr_.setPosition(sf::Vector2f(0.0f, static_cast<float>(i << 4)));
				rt0->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(192, 16, 16, 16));
			for (int i = 1; i != middle_Y; i++) {
				spr_.setPosition(sf::Vector2f(0.0f, static_cast<float>(i << 4)));
				rt1->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(192, 32, 16, 16));
			for (int i = 1; i != middle_Y; i++) {
				spr_.setPosition(sf::Vector2f(0.0f, static_cast<float>(i << 4)));
				rt2->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(208, 0, 16, 16));
			for (int i = 1; i != middle_Y; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(wdx - 16), static_cast<float>(i << 4)));
				rt0->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(208, 16, 16, 16));
			for (int i = 1; i != middle_Y; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(wdx - 16), static_cast<float>(i << 4)));
				rt1->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(208, 32, 16, 16));
			for (int i = 1; i != middle_Y; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(wdx - 16), static_cast<float>(i << 4)));
				rt2->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(224, 0, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), static_cast<float>(wdy - 16)));
				rt0->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(224, 16, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), static_cast<float>(wdy - 16)));
				rt1->draw(spr_);
			}
			spr_.setTextureRect(sf::IntRect(224, 32, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), static_cast<float>(wdy - 16)));
				rt2->draw(spr_);
			}

			spr_.setTextureRect(sf::IntRect(240, 0, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				for (int j = 1; j != middle_Y; j++) {
					spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), static_cast<float>(j << 4)));
					rt0->draw(spr_);
				}
			}
			spr_.setTextureRect(sf::IntRect(240, 16, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				for (int j = 1; j != middle_Y; j++) {
					spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), static_cast<float>(j << 4)));
					rt1->draw(spr_);
				}
			}
			spr_.setTextureRect(sf::IntRect(240, 32, 16, 16));
			for (int i = 1; i != middle_X; i++) {
				for (int j = 1; j != middle_Y; j++) {
					spr_.setPosition(sf::Vector2f(static_cast<float>(i << 4), static_cast<float>(j << 4)));
					rt2->draw(spr_);
				}
			}

			spr_.setPosition(sf::Vector2f(0.0f, static_cast<float>(wdy - 16)));
			spr_.setTextureRect(sf::IntRect(144, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(144, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(144, 32, 16, 16));
			rt2->draw(spr_);
			spr_.setPosition(sf::Vector2f(static_cast<float>(wdx - 16), static_cast<float>(wdy - 16)));
			spr_.setTextureRect(sf::IntRect(160, 0, 16, 16));
			rt0->draw(spr_);
			spr_.setTextureRect(sf::IntRect(160, 16, 16, 16));
			rt1->draw(spr_);
			spr_.setTextureRect(sf::IntRect(160, 32, 16, 16));
			rt2->draw(spr_);
		}
	}
	rt0->display();
	rt1->display();
	rt2->display();
	rtx[0] = rt0;
	rtx[1] = rt1;
	rtx[2] = rt2;
	textures_button_.at((wdx >> 4) - 1).at((wdy >> 4) - 1).first = true;
}


void TextureLoader::initializeTexture_Bar(int wdx, int wdy) {
	int xdy = wdx / wdy;
#ifdef _DEBUG
	if (wdx <= 0 || wdy <= 0) {
		throw "wdx and wdy must be positive.";
	}
	if ((wdy & 0b111) != 0) {
		throw "wdy should be 16 times N.";
	}
	if ((wdx % wdy) != 0) {
		throw "wdx should be wdy times N.";
	}
	if (xdy > TEXTURES_BAR_X) {
		throw "wdx is too big.";
	}
	if ((wdy >> 4) > TEXTURES_BAR_X) {
		throw "wdy is too big.";
	}
	if (textures_bar_.at(xdy - 1).at((wdy >> 4) - 1).first) {
		throw "button render_texture already initialized.";
	}
#endif
	sf::RenderTexture** rtx = &textures_bar_.at(xdy - 1).at((wdy >> 4) - 1).second[0];
	sf::RenderTexture* rt0 = new sf::RenderTexture;
	sf::RenderTexture* rt1 = new sf::RenderTexture;
	sf::RenderTexture* rt2 = new sf::RenderTexture;
	rt0->create(wdx, wdy);
	rt1->create(wdx, wdy);
	rt2->create(wdx, wdy);

	if (xdy == 1) {
		spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
		spr_.setTextureRect(sf::IntRect(0, 48, 8, 16));
		rt0->draw(spr_);
		spr_.setTextureRect(sf::IntRect(0, 64, 8, 16));
		rt1->draw(spr_);
		spr_.setTextureRect(sf::IntRect(0, 80, 8, 16));
		rt2->draw(spr_);
		spr_.setPosition(sf::Vector2f(8.0f, 0.0f));
		spr_.setTextureRect(sf::IntRect(248, 48, 8, 16));
		rt0->draw(spr_);
		spr_.setTextureRect(sf::IntRect(248, 64, 8, 16));
		rt1->draw(spr_);
		spr_.setTextureRect(sf::IntRect(248, 80, 8, 16));
		rt2->draw(spr_);
	} else if (xdy <= 16) {
		spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
		spr_.setScale(sf::Vector2f(static_cast<float>(wdy >> 4), static_cast<float>(wdy >> 4)));
		spr_.setTextureRect(sf::IntRect(0, 48, 16, 16));
		rt0->draw(spr_);
		spr_.setTextureRect(sf::IntRect(0, 64, 16, 16));
		rt1->draw(spr_);
		spr_.setTextureRect(sf::IntRect(0, 80, 16, 16));
		rt2->draw(spr_);
		spr_.setPosition(sf::Vector2f(static_cast<float>(wdy), 0.0f));
		spr_.setTextureRect(sf::IntRect((17 - xdy) << 4, 48, (xdy - 1) << 4, 16));
		rt0->draw(spr_);
		spr_.setTextureRect(sf::IntRect((17 - xdy) << 4, 64, (xdy - 1) << 4, 16));
		rt1->draw(spr_);
		spr_.setTextureRect(sf::IntRect((17 - xdy) << 4, 80, (xdy - 1) << 4, 16));
		rt2->draw(spr_);
		spr_.setScale(sf::Vector2f(1.0f, 1.0f));
	} else {
	#ifdef _DEBUG
		throw "too long so not prepared yet.";
	#endif
	}

	rt0->display();
	rt1->display();
	rt2->display();
	rtx[0] = rt0;
	rtx[1] = rt1;
	rtx[2] = rt2;
	textures_bar_.at(xdy - 1).at((wdy >> 4) - 1).first = true;

	if (!textures_bar_handle_.at((wdy >> 4) - 1).first) {
		sf::RenderTexture** rtxh = &textures_bar_handle_.at((wdy >> 4) - 1).second[0];
		sf::RenderTexture* rth0 = new sf::RenderTexture;
		sf::RenderTexture* rth1 = new sf::RenderTexture;
		sf::RenderTexture* rth2 = new sf::RenderTexture;
		rth0->create(wdy, wdy);
		rth1->create(wdy, wdy);
		rth2->create(wdy, wdy);

		spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
		spr_.setScale(sf::Vector2f(static_cast<float>(wdy >> 4), static_cast<float>(wdy >> 4)));
		spr_.setTextureRect(sf::IntRect(256, 48, 16, 16));
		rth0->draw(spr_);
		spr_.setTextureRect(sf::IntRect(256, 64, 16, 16));
		rth1->draw(spr_);
		spr_.setTextureRect(sf::IntRect(256, 80, 16, 16));
		rth2->draw(spr_);
		spr_.setScale(sf::Vector2f(1.0f, 1.0f));

		rth0->display();
		rth1->display();
		rth2->display();
		rtxh[0] = rth0;
		rtxh[1] = rth1;
		rtxh[2] = rth2;
		textures_bar_handle_.at((wdy >> 4) - 1).first = true;
	}

}

void TextureLoader::initializeTexture_Movebar() {
	textures_movebar_[0].setRepeated(true);
	textures_movebar_[1].setRepeated(true);
	textures_movebar_[2].setRepeated(true);
	textures_movebar_[0].create(16, 16);
	textures_movebar_[1].create(16, 16);
	textures_movebar_[2].create(16, 16);
	spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
	spr_.setTextureRect(sf::IntRect(0, 96, 16, 16));
	textures_movebar_[0].draw(spr_);
	spr_.setTextureRect(sf::IntRect(0, 112, 16, 16));
	textures_movebar_[1].draw(spr_);
	spr_.setTextureRect(sf::IntRect(0, 128, 16, 16));
	textures_movebar_[2].draw(spr_);
	textures_movebar_[0].display();
	textures_movebar_[1].display();
	textures_movebar_[2].display();
}

void TextureLoader::initializeTexture_GameOverlay_Btn() {
	spr_.setPosition(sf::Vector2f(0.0f, 0.0f));
	for (int i = 0; i != 10; i++) {
		spr_.setTextureRect(sf::IntRect(i * 48, 144, 48, 48));
		textures_gameoverlay_btn_[i].create(48, 48);
		textures_gameoverlay_btn_[i].draw(spr_);
		textures_gameoverlay_btn_[i].display();
	}
	for (int i = 10; i != 19; i++) {
		spr_.setTextureRect(sf::IntRect((i - 10) * 48, 192, 48, 48));
		textures_gameoverlay_btn_[i].create(48, 48);
		textures_gameoverlay_btn_[i].draw(spr_);
		textures_gameoverlay_btn_[i].display();
	}
	for (int i = 19; i != 23; i++) {
		spr_.setTextureRect(sf::IntRect((i - 19) * 48, 240, 48, 48));
		textures_gameoverlay_btn_[i].create(48, 48);
		textures_gameoverlay_btn_[i].draw(spr_);
		textures_gameoverlay_btn_[i].display();
	}
}


void TextureLoader::initializeTexture_other() {
  texture_selection_.create(54, 54);
	spr_.setTextureRect(sf::IntRect(0, 288, 54, 54));
  texture_selection_.draw(spr_);
	texture_selection_.display();
}

}  // namespace ch