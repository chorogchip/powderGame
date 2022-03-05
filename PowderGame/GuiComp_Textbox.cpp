#include "GuiComp_Textbox.h"

#include "Game.h"


namespace ch {


GuiComp_Textbox::GuiComp_Textbox(ch::EnumSides side, int xGap, int yGap, int width, int height, int textbox_text_size, EnumTextboxKinds textboxKind)
  : GuiComponent(side, xGap, yGap, width, height), text_size_(textbox_text_size), kind_(textboxKind), wstr_(L"") {

  Game::getInstance()->getTextureLoader().setTexture_Button(sf_sprite_[0], sf_sprite_[1], sf_sprite_[2], width, height);

  sf_text_.setFont(Game::getInstance()->getFont(ch::EnumGameFonts::BASIC));
  //sf_text_.setString(text);
  sf_text_.setFillColor(sf::Color::Black);
  sf_text_.setCharacterSize(textbox_text_size);
}

GuiComp_Textbox::~GuiComp_Textbox() { }

void GuiComp_Textbox::setTransformedAABB_(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) {
  sf_sprite_[0].setPosition(getTransformedAABB().pos);
  sf_sprite_[1].setPosition(getTransformedAABB().pos);
  sf_sprite_[2].setPosition(getTransformedAABB().pos);
  sf_sprite_[0].setScale(sf::Vector2f(GUI_scale, GUI_scale));
  sf_sprite_[1].setScale(sf::Vector2f(GUI_scale, GUI_scale));
  sf_sprite_[2].setScale(sf::Vector2f(GUI_scale, GUI_scale));

  sf_text_.setCharacterSize(static_cast<unsigned int>(text_size_ * GUI_scale));
  sf_text_.setPosition(getTransformedAABB().pos);
}


void GuiComp_Textbox::inputUnicode(int unicode) {

  if (unicode > 0x0020 && unicode != 0x7F) {
    switch (kind_) {
    case EnumTextboxKinds::UNSIGNED_INT:
      if (unicode < '0' || unicode > '9') { return; } break;
    case EnumTextboxKinds::SIGNED_INT:
      if (unicode >= '0' && unicode <= '9') {
        break;
      } else if (unicode == '+' || unicode == '-') {
        if (wstr_.length() == 0U) {
          break;
        } else {
          return;
        }
      } else {
        return;
      }
      break;
    case EnumTextboxKinds::TEXT_LINE:
      if (unicode == '\n') { return; } break;
    case EnumTextboxKinds::TEXT_BOX:
      break;
    }
    wchar_t wch = static_cast<wchar_t>(unicode);
    wstr_.insert(wstr_.begin() + wstr_cursor_, wch);
    wstr_cursor_++;
    sf_text_.setString(wstr_);
  }
}

void GuiComp_Textbox::inputKeyboard(sf::Keyboard::Key keyboard) {

  switch (keyboard) {

  case sf::Keyboard::Key::BackSpace:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)) {
      std::size_t res = wstr_.find_last_of(L" \n", static_cast<std::size_t>(wstr_cursor_ - 2));
      if (res != std::wstring::npos) {
        wstr_.erase(wstr_.begin() + res + 1, wstr_.begin() + wstr_cursor_);
        sf_text_.setString(wstr_);
        wstr_cursor_ = static_cast<int>(res) + 1;
      } else {
        wstr_.erase(0, wstr_cursor_);
        sf_text_.setString(wstr_);
        wstr_cursor_ = 0;
      }
    } else {
      if (wstr_cursor_ > 0) {
        wstr_cursor_--;
        wstr_.erase(wstr_.begin() + wstr_cursor_);
        sf_text_.setString(wstr_);
      }
    }
    break;
  case sf::Keyboard::Key::Delete:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)) {
      std::size_t res = wstr_.find_first_of(L" \n", static_cast<std::size_t>(wstr_cursor_));
      if (res != std::wstring::npos) {
        wstr_.erase(wstr_.begin() + wstr_cursor_, wstr_.begin() + res + 1);
        sf_text_.setString(wstr_);
      } else {
        wstr_.erase(wstr_.begin() + wstr_cursor_, wstr_.end());
        sf_text_.setString(wstr_);
        wstr_cursor_ = static_cast<int>(wstr_.length());
      }
    } else {
      if (wstr_cursor_ < static_cast<int>(wstr_.length())) {
        wstr_.erase(wstr_.begin() + wstr_cursor_);
        sf_text_.setString(wstr_);
      }
    }
    break;
  case sf::Keyboard::Key::Space:
    if (isText(kind_)) {
      wstr_.insert(wstr_.begin() + wstr_cursor_, L' ');
      wstr_cursor_++;
      sf_text_.setString(wstr_);
    }
    break;
  case sf::Keyboard::Key::Tab:
    if (isText(kind_)) {
      wstr_.insert(wstr_.begin() + wstr_cursor_, L'\t');
      wstr_cursor_++;
      sf_text_.setString(wstr_);
    }
    break;
  case sf::Keyboard::Key::Enter:
    if (kind_ == EnumTextboxKinds::TEXT_BOX) {
      wstr_.insert(wstr_.begin() + wstr_cursor_, L'\n');
      wstr_cursor_++;
      sf_text_.setString(wstr_);
    } else {
      cookNum();
      state_ = EnumGui3State::DEFAULT;
      Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
    }
    break;
  case sf::Keyboard::Key::Left:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)) {
      std::size_t res = wstr_.find_last_of(L" \n", static_cast<std::size_t>(wstr_cursor_ - 2));
      if (res != std::wstring::npos) {
        wstr_cursor_ = static_cast<int>(res) + 1;
      } else {
        wstr_cursor_ = 0;
      }
    } else {
      wstr_cursor_--;
      if (wstr_cursor_ < 0) {
        wstr_cursor_ = 0;
      }
    }
    break;
  case sf::Keyboard::Key::Right:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)) {
      std::size_t res = wstr_.find_first_of(L" \n", static_cast<std::size_t>(wstr_cursor_));
      if (res != std::wstring::npos) {
        wstr_cursor_ = static_cast<int>(res) + 1;
      } else {
        wstr_cursor_ = static_cast<int>(wstr_.length());
      }
    } else {
      wstr_cursor_++;
      if (wstr_cursor_ > static_cast<int>(wstr_.length())) {
        wstr_cursor_ = static_cast<int>(wstr_.length());
      }
    }
    break;
  case sf::Keyboard::Key::Up:
    break;
  case sf::Keyboard::Key::Down:
    break;
  case sf::Keyboard::Key::Home:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)) {
      wstr_cursor_ = 0;
    } else {
      std::size_t res = wstr_.rfind(L'\n', static_cast<std::size_t>(wstr_cursor_ - 1));
      if (res != std::wstring::npos) {
        wstr_cursor_ = static_cast<int>(res) + 1;
      } else {
        wstr_cursor_ = 0;
      }
    }
    break;
  case sf::Keyboard::Key::End:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)) {
      wstr_cursor_ = static_cast<int>(wstr_.length());
    } else {
      std::size_t res = wstr_.find(L'\n', static_cast<std::size_t>(wstr_cursor_));
      if (res != std::wstring::npos) {
        wstr_cursor_ = static_cast<int>(res);
      } else {
        wstr_cursor_ = static_cast<int>(wstr_.length());
      }
    }
    break;
  case sf::Keyboard::Key::Escape:
    cookNum();
    state_ = EnumGui3State::DEFAULT;
    Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
    break;

  default: break;
  }
}


void GuiComp_Textbox::setWStr(std::wstring wstr) {
  wstr_ = wstr;
  wstr_cursor_ = wstr_.length();
  sf_text_.setString(wstr);
}

void GuiComp_Textbox::cookNum() {
  auto length = wstr_.length();
  if (kind_ == EnumTextboxKinds::UNSIGNED_INT) {
    if (length == 0U) {
      setWStr(std::to_wstring(var_default_));
    } else if (length > static_cast<size_t>(log10(static_cast<double>(std::numeric_limits<unsigned int>::max())) + 3)) {
      setWStr(std::to_wstring(limit_max_));
    } else {
      long long wstr_var = stoll(wstr_);
      if (wstr_var < limit_min_) {
        setWStr(std::to_wstring(limit_min_));
      } else if (wstr_var > limit_max_) {
        setWStr(std::to_wstring(limit_max_));
      }
    }
  } else if (kind_ == EnumTextboxKinds::SIGNED_INT) {
    if (length == 0U || ((length == 1U) && (wstr_.front() == L'-'))) {
      setWStr(std::to_wstring(var_default_));
    } else if (length > static_cast<size_t>(log10(static_cast<double>(std::numeric_limits<int>::max())) + 3)) {
      if (wstr_.front() == L'-') {
        setWStr(std::to_wstring(limit_min_));
      } else {
        setWStr(std::to_wstring(limit_max_));
      }
    } else {
      long long wstr_var = stoll(wstr_);
      if (wstr_var < limit_min_) {
        setWStr(std::to_wstring(limit_min_));
      } else if (wstr_var > limit_max_) {
        setWStr(std::to_wstring(limit_max_));
      }
    }
  }
}

void GuiComp_Textbox::setLimits(long long var_default, long long limit_min, long long limit_max) {

  if (kind_ == EnumTextboxKinds::UNSIGNED_INT) {

    if (std::in_range<unsigned int>(var_default)) {
      var_default_ = var_default;
      setWStr(std::to_wstring(var_default_));
    }
    if (std::in_range<unsigned int>(limit_min)) {
      limit_min_ = limit_min;
    }
    if (std::in_range<unsigned int>(limit_max)) {
      limit_max_ = limit_max;
    }

  } else if (kind_ == EnumTextboxKinds::SIGNED_INT) {

    if (std::in_range<int>(var_default)) {
      var_default_ = var_default;
    }

  #ifdef _DEBUG
    else { throw("var_default in textbox is out of range!"); }
  #endif

    if (std::in_range<int>(limit_min)) {
      limit_min_ = limit_min;
    }

  #ifdef _DEBUG
    else { throw("var_default in textbox is out of range!"); }
  #endif

    if (std::in_range<int>(limit_max)) {
      limit_max_ = limit_max;
    }

  #ifdef _DEBUG
    else { throw("var_default in textbox is out of range!"); }
  #endif


  }
}

void GuiComp_Textbox::render(sf::RenderWindow& window) const {
  window.draw(sf_sprite_[static_cast<int>(state_)]);
  window.draw(sf_text_);
}


}

