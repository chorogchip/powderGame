#include "SceneEventHandler.h"
#include "../main/Game.h"


namespace ch {


SceneEventHandler::SceneEventHandler() { }


SceneEventHandler::~SceneEventHandler() { }


ch::EnumActionResult  SceneEventHandler::onEvent_MouseEntered(Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_MouseEntered(res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_mouse_entered(res_scene);

	return res_scene;
}

ch::EnumActionResult  SceneEventHandler::onEvent_MouseLeft(Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_MouseLeft(res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_mouse_left(res_scene);

	return res_scene;
}

ch::EnumActionResult  SceneEventHandler::onEvent_TextEntered(sf::Event::TextEvent& evnt, Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	/*
	wchar_t ww = evnt.unicode;
	std::wcout << ww << std::endl;
	PRTLOG(evnt.unicode << std::endl);
	*/

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_TextEntered(evnt, res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_text_entered(evnt, res_scene);

	return res_scene;
}

ch::EnumActionResult  SceneEventHandler::onEvent_KeyPressed(sf::Event::KeyEvent& evnt, Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_KeyPressed(evnt, res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_key_pressed(evnt, res_scene);

	return res_scene;
}

ch::EnumActionResult  SceneEventHandler::onEvent_KeyReleased(sf::Event::KeyEvent& evnt, Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_KeyReleased(evnt, res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_key_released(evnt, res_scene);

	return res_scene;
}

ch::EnumActionResult  SceneEventHandler::onEvent_MouseWheelScrolled(sf::Event::MouseWheelScrollEvent& evnt, Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_MouseWheelScrolled(evnt, res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_mouse_wheel_scrolled(evnt, res_scene);

	return res_scene;
}

ch::EnumActionResult  SceneEventHandler::onEvent_MouseButtonPressed(sf::Event::MouseButtonEvent& evnt, Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_MouseButtonPressed(evnt, res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_mouse_button_pressed(evnt, res_scene);

	return res_scene;
}

ch::EnumActionResult  SceneEventHandler::onEvent_MouseButtonReleased(sf::Event::MouseButtonEvent& evnt, Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_MouseButtonReleased(evnt, res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_mouse_button_released(evnt, res_scene);

	return res_scene;
}

ch::EnumActionResult  SceneEventHandler::onEvent_MouseMoved(sf::Event::MouseMoveEvent& evnt, Scene& scene) {
	ch::EnumActionResult res_scene = ch::EnumActionResult::SKIPPED;

	for (auto it = scene.guis_.rbegin(); it != scene.guis_.rend(); it++) {
		res_scene = (*it)->onEvent_MouseMoved(evnt, res_scene);
		if (!ch::toSkip(res_scene)) {
			return res_scene;
		}
	}

	res_scene = scene.onEvent_mouse_moved(evnt, res_scene);

	return res_scene;
}


}