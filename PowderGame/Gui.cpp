#include "Gui.h"



Gui::Gui() {}


Gui::~Gui() {}

EnumActionResult Gui::handleEvent(sf::Event& evnt) {

	EnumActionResult res = handleEvent_(evnt);
	if (res != EnumActionResult::SKIPPED) {
		return res;
	}

	//

	return EnumActionResult::SKIPPED;
}
void Gui::tick() {
	tick_();

	//


}
void Gui::render() {

	//

	render_();
}