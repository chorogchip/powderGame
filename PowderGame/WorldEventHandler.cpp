#include "WorldEventHandler.h"



namespace ch {


WorldEventHandler::WorldEventHandler() { }


WorldEventHandler::~WorldEventHandler() { }


ch::EnumActionResult WorldEventHandler::onEvent_MouseEntered(World& scene, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult WorldEventHandler::onEvent_MouseLeft(World& scene, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult WorldEventHandler::onEvent_TextEntered(sf::Event::TextEvent& evnt, World& world, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult WorldEventHandler::onEvent_KeyPressed(sf::Event::KeyEvent& evnt, World& world, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult WorldEventHandler::onEvent_KeyReleased(sf::Event::KeyEvent& evnt, World& world, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult WorldEventHandler::onEvent_MouseWheelScrolled(sf::Event::MouseWheelScrollEvent& evnt, World& world, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult WorldEventHandler::onEvent_MouseButtonPressed(sf::Event::MouseButtonEvent& evnt, World& world, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult WorldEventHandler::onEvent_MouseButtonReleased(sf::Event::MouseButtonEvent& evnt, World& world, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult WorldEventHandler::onEvent_MouseMoved(sf::Event::MouseMoveEvent& evnt, World& world, ch::EnumActionResult prev) {
  return prev;
}

}