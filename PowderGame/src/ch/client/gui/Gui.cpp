#include "Gui.h"
#include "../../main/Game.h"

namespace ch {

Gui::Gui(ch::EnumSides side, float xPos, float yPos, float width, float height) :
  FittablePosition(side, xPos, yPos, width, height) { }

Gui::~Gui() { }

/*

Game 전체에서 하나의 Gui 구성요소(버튼, 바 등)를 hold할수있다
gameoptions에 어떤종류 hold했는지 정해진다

업데이트할때:
resized, mouseButtonPressed, mouseButtonReleased, mouseMoved,
gui 추가/제거, 기타 gui 내부 변화

버튼은 hold하던것만 released했을때 클릭된다
hold하다가 벗어나면 hold 풀린다
마우스떼면 hold 풀린다

바는 hold하는 상태에서 마우스를 움직이면 바가 움직인다
마우스떼면 hold풀린다

버튼색칠은 hold와 상관없이 영역으로 이루어진다
버튼색칠도 한번에 Game당 하나만 된다
한번에하나 기능은 위에있는Gui가 점유했을때 Applied를 리턴하는것으로 구현한다

gui의 빈 영역으로 전에 생성된 gui를 가릴수있다
gui는 무조건 스택으로 작동한다

*/

ch::EnumActionResult Gui::onEvent_MouseEntered(ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Gui::onEvent_MouseLeft(ch::EnumActionResult prev) {
  return updateMouse(-1, -1, prev);;
}
ch::EnumActionResult Gui::onEvent_TextEntered(sf::Event::TextEvent& evnt, ch::EnumActionResult prev) {

  if (prev == ch::EnumActionResult::SKIPPED) {
    if (Game::getInstance()->game_options_.holding_component == ch::EnumHoldingComponent::TEXTBOX) {

      for (auto it = gui_textboxes_.rbegin(); it != gui_textboxes_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          it->inputUnicode(evnt.unicode);
          return ch::EnumActionResult::APPLIED;
        }
      }
    }
  }
  return prev;
}

ch::EnumActionResult Gui::onEvent_KeyPressed(sf::Event::KeyEvent& evnt, ch::EnumActionResult prev) {

  if (prev == ch::EnumActionResult::SKIPPED) {
    if (Game::getInstance()->game_options_.holding_component == ch::EnumHoldingComponent::TEXTBOX) {

      for (auto it = gui_textboxes_.rbegin(); it != gui_textboxes_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          it->inputKeyboard(evnt);
          return ch::EnumActionResult::APPLIED;
        }
      }
    } else if (this->is_closable_by_esc_key_ && evnt.code == sf::Keyboard::Escape) {
      this->to_close_ = true;
      return ch::EnumActionResult::APPLIED;
    }
  }
  return prev;
}

ch::EnumActionResult Gui::onEvent_KeyReleased(sf::Event::KeyEvent& evnt, ch::EnumActionResult prev) {

  return prev;
}

ch::EnumActionResult Gui::onEvent_MouseWheelScrolled(sf::Event::MouseWheelScrollEvent& evnt, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Gui::onEvent_MouseButtonPressed(sf::Event::MouseButtonEvent& evnt, ch::EnumActionResult prev) {


  if (prev == ch::EnumActionResult::SKIPPED) {

    // not applied

    if (Game::getInstance()->game_options_.holding_component == ch::EnumHoldingComponent::TEXTBOX) {
      for (auto it = gui_textboxes_.rbegin(); it != gui_textboxes_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          it->cookNum();
          it->state_ = EnumGui3State::DEFAULT;
        }
      }
    }

    for (auto it = gui_buttons_.rbegin(); it != gui_buttons_.rend(); it++) {
      if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getTransformedAABB())) {
        it->state_ = EnumGui3State::PRESSED;
        Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::BUTTON;
        return ch::EnumActionResult::APPLIED;
      }
    }
    for (auto it = gui_bars_.rbegin(); it != gui_bars_.rend(); it++) {
      if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getBarHandleCollisionBox())) {
        it->state_ = EnumGui3State::PRESSED;
        Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::BAR;
        return ch::EnumActionResult::APPLIED;
      } else if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getBarCollisionBox())) {
        it->state_ = EnumGui3State::PRESSED;
        ch::sfAABB sfaabb = it->getBarCollisionBox();
        it->setGaugeCurrent((((evnt.x - static_cast<int>(sfaabb.pos.x)) * (it->getGaugeMax())) + (static_cast<int>(sfaabb.size.x) >> (1)))
                              / (static_cast<int>(sfaabb.size.x)));
        Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::BAR;
        return ch::EnumActionResult::APPLIED;
      }
    }
    for (auto it = gui_textboxes_.rbegin(); it != gui_textboxes_.rend(); it++) {
      if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getTransformedAABB())) {
        it->state_ = EnumGui3State::PRESSED;
        Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::TEXTBOX;
        return ch::EnumActionResult::APPLIED;
      }
    }
    for (auto it = gui_movebars_.rbegin(); it != gui_movebars_.rend(); it++) {
      if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getTransformedAABB())) {
        it->state_ = EnumGui3State::PRESSED;
        Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::MOVEBAR;
        Game::getInstance()->game_options_.clicked_pos = sf::Vector2i(evnt.x, evnt.y);
        return ch::EnumActionResult::APPLIED;
      }
    }
    for (auto it = gui_backgrounds_.rbegin(); it != gui_backgrounds_.rend(); it++) {
      if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getTransformedAABB())) {
        it->state_ = EnumGui3State::PRESSED;
        Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::BACKGROUND;
        return ch::EnumActionResult::APPLIED;
      }
    }

    return prev;

  } else {
    
    // applied
    return prev;

  }
}

ch::EnumActionResult Gui::onEvent_MouseButtonReleased(sf::Event::MouseButtonEvent& evnt, ch::EnumActionResult prev) {

  if (prev == ch::EnumActionResult::SKIPPED) {

    // not applied
    auto holding = Game::getInstance()->game_options_.holding_component;
    if (holding == ch::EnumHoldingComponent::BUTTON) {
      for (auto it = gui_buttons_.rbegin(); it != gui_buttons_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          // press button code
          switch (it->getMoveType()) {
          case EnumButtonMove::NOTHING:
          default:
            break;
          case EnumButtonMove::CLOSE_THIS_GUI:
            to_close_ = true;
            break;
          case EnumButtonMove::DO_FUNCTION_POINTER:
            it->onClicked();
            break;
          }

          it->state_ = EnumGui3State::MOUSE_ON;
          Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
          return ch::EnumActionResult::APPLIED;
        }
      }
    } else if (holding == ch::EnumHoldingComponent::BAR) {
      for (auto it = gui_bars_.rbegin(); it != gui_bars_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getBarHandleCollisionBox()) || ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getBarCollisionBox())) {
            it->state_ = EnumGui3State::MOUSE_ON;
          } else {
            it->state_ = EnumGui3State::DEFAULT;
          }
          Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
          return ch::EnumActionResult::APPLIED;
        }
      }
    } else if (holding == ch::EnumHoldingComponent::TEXTBOX) {
      for (auto it = gui_textboxes_.rbegin(); it != gui_textboxes_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getTransformedAABB())) {

          } else {
            it->cookNum();
            it->state_ = EnumGui3State::DEFAULT;
            Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
          }
          return ch::EnumActionResult::APPLIED;
        }
      }
    } else if (holding == ch::EnumHoldingComponent::MOVEBAR) {
      for (auto it = gui_movebars_.rbegin(); it != gui_movebars_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          if (ch::isInAABB_HalfOpened(evnt.x, evnt.y, it->getTransformedAABB())) {
            it->state_ = EnumGui3State::MOUSE_ON;
          } else {
            it->state_ = EnumGui3State::DEFAULT;
          }
          Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
          return ch::EnumActionResult::APPLIED;
        }
      }
    } else if (holding == ch::EnumHoldingComponent::BACKGROUND) {
      for (auto it = gui_backgrounds_.rbegin(); it != gui_backgrounds_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          it->state_ = EnumGui3State::MOUSE_ON;
          Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
          return ch::EnumActionResult::APPLIED;
        }
      }
    } else {

      return prev;
    }

    return prev;

  } else {

    // applied
    return prev;

  }
}

ch::EnumActionResult Gui::onEvent_MouseMoved(sf::Event::MouseMoveEvent& evnt, ch::EnumActionResult prev) {

  return updateMouse(evnt.x, evnt.y, prev);

}


inline void Gui::setAllComponentDefault() {
  for (auto it = gui_buttons_.rbegin(); it != gui_buttons_.rend(); it++) {
    it->state_ = EnumGui3State::DEFAULT;
  }
  for (auto it = gui_bars_.rbegin(); it != gui_bars_.rend(); it++) {
    it->state_ = EnumGui3State::DEFAULT;
  }
  for (auto it = gui_backgrounds_.rbegin(); it != gui_backgrounds_.rend(); it++) {
    it->state_ = EnumGui3State::DEFAULT;
  }
  for (auto it = gui_movebars_.rbegin(); it != gui_movebars_.rend(); it++) {
    it->state_ = EnumGui3State::DEFAULT;
  }
  for (auto it = gui_textboxes_.rbegin(); it != gui_textboxes_.rend(); it++) {
    it->state_ = EnumGui3State::DEFAULT;
  }
}


inline ch::EnumActionResult Gui::updateMouse(int mouseX, int mouseY, ch::EnumActionResult prev) {

  if (prev == ch::EnumActionResult::SKIPPED) {

    auto holding = Game::getInstance()->game_options_.holding_component;
    if (holding == ch::EnumHoldingComponent::BAR) {

      for (auto it = gui_bars_.rbegin(); it != gui_bars_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          setAllComponentDefault();
          it->state_ = EnumGui3State::PRESSED;

          ch::sfAABB sfaabb = it->getBarCollisionBox();
          it->setGaugeCurrent((((mouseX - static_cast<int>(sfaabb.pos.x)) * (it->getGaugeMax())) + (static_cast<int>(sfaabb.size.x) >> (1)))
                                / (static_cast<int>(sfaabb.size.x)));

          prev = ch::EnumActionResult::APPLIED;
          return prev;
        }
      }

      setAllComponentDefault();
      return prev;

    } else if (holding == ch::EnumHoldingComponent::MOVEBAR) {

      for (auto it = gui_movebars_.rbegin(); it != gui_movebars_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          setAllComponentDefault();
          it->state_ = EnumGui3State::PRESSED;

          sf::Vector2i clicked = Game::getInstance()->game_options_.clicked_pos;
          sf::Vector2u winsize = Game::getInstance()->getWindow().getSize();
          this->setPosision(this->get_xGap() + mouseX - clicked.x, this->get_yGap() + mouseY - clicked.y,
                            0.0f, 0.0f, static_cast<float>(winsize.x), static_cast<float>(winsize.y), Game::getInstance()->getRenderstate().ui_scale);
          Game::getInstance()->game_options_.clicked_pos = sf::Vector2i(mouseX, mouseY);
          return ch::EnumActionResult::APPLIED;
        }
      }

      setAllComponentDefault();
      return prev;

    } else if (holding == ch::EnumHoldingComponent::TEXTBOX) {

      for (auto it = gui_textboxes_.rbegin(); it != gui_textboxes_.rend(); it++) {
        if (it->state_ == EnumGui3State::PRESSED) {
          setAllComponentDefault();
          it->state_ = EnumGui3State::PRESSED;

          return ch::EnumActionResult::APPLIED;
        }
      }

      setAllComponentDefault();
      return prev;

    } else {

      for (auto it = gui_buttons_.rbegin(); it != gui_buttons_.rend(); it++) {
        if (ch::isInAABB_HalfOpened(mouseX, mouseY, it->getTransformedAABB())) {
          if (it->state_ == EnumGui3State::PRESSED) {
            setAllComponentDefault();
            it->state_ = EnumGui3State::PRESSED;
          } else {
            setAllComponentDefault();
            it->state_ = EnumGui3State::MOUSE_ON;
          }
          return ch::EnumActionResult::APPLIED;
        } else if (it->state_ == EnumGui3State::PRESSED) {
          it->state_ = EnumGui3State::DEFAULT;
          Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
        }
      }
      for (auto it = gui_bars_.rbegin(); it != gui_bars_.rend(); it++) {
        if (ch::isInAABB_HalfOpened(mouseX, mouseY, it->getBarCollisionBox()) || ch::isInAABB_HalfOpened(mouseX, mouseY, it->getBarHandleCollisionBox())) {
          setAllComponentDefault();
          it->state_ = EnumGui3State::MOUSE_ON;
          return ch::EnumActionResult::APPLIED;
        }
      }
      for (auto it = gui_textboxes_.rbegin(); it != gui_textboxes_.rend(); it++) {
        if (ch::isInAABB_HalfOpened(mouseX, mouseY, it->getTransformedAABB())) {
          setAllComponentDefault();
          it->state_ = EnumGui3State::MOUSE_ON;
          return ch::EnumActionResult::APPLIED;
        }
      }
      for (auto it = gui_movebars_.rbegin(); it != gui_movebars_.rend(); it++) {
        if (ch::isInAABB_HalfOpened(mouseX, mouseY, it->getTransformedAABB())) {
          setAllComponentDefault();
          it->state_ = EnumGui3State::MOUSE_ON;
          return ch::EnumActionResult::APPLIED;
        }
      }
      for (auto it = gui_backgrounds_.rbegin(); it != gui_backgrounds_.rend(); it++) {
        if (ch::isInAABB_HalfOpened(mouseX, mouseY, it->getTransformedAABB())) {
          setAllComponentDefault();
          it->state_ = EnumGui3State::MOUSE_ON;
          return ch::EnumActionResult::APPLIED;
        } else if (it->state_ == EnumGui3State::PRESSED) {
          it->state_ = EnumGui3State::DEFAULT;
          Game::getInstance()->game_options_.holding_component = ch::EnumHoldingComponent::NOTHING;
        }
      }

      setAllComponentDefault();
      return prev;
    }
  } else {
    setAllComponentDefault();
    return prev;
  }
}


void Gui::update() { }

void Gui::render() const {

  auto& rdwd = Game::getInstance()->getWindow();

  for (auto& o : gui_backgrounds_) {
    o.render(rdwd);
  }
  for (auto& o : gui_movebars_) {
    o.render(rdwd);
  }
  for (auto& o : gui_textboxes_) {
    o.render(rdwd);
  }
  for (auto& o : gui_bars_) {
    o.render(rdwd);
  }
  for (auto& o : gui_buttons_) {
    o.render(rdwd);
  }
  for (auto& o : gui_textholders_) {
    o.render(rdwd);
  }
  for (auto& o : gui_sprites_) {
    o.render(rdwd);
  }
}

void Gui::setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) {

  for (auto& o : gui_backgrounds_) {
    o.setTransformedAABB(getTransformedAABB(), scale);
  }
  for (auto& o : gui_movebars_) {
    o.setTransformedAABB(getTransformedAABB(), scale);
  }
  for (auto& o : gui_textboxes_) {
    o.setTransformedAABB(getTransformedAABB(), scale);
  }
  for (auto& o : gui_bars_) {
    o.setTransformedAABB(getTransformedAABB(), scale);
  }
  for (auto& o : gui_buttons_) {
    o.setTransformedAABB(getTransformedAABB(), scale);
  }
  for (auto& o : gui_textholders_) {
    o.setTransformedAABB(getTransformedAABB(), scale);
  }
  for (auto& o : gui_sprites_) {
    o.setTransformedAABB(getTransformedAABB(), scale);
  }
}


}