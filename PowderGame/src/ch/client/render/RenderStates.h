#pragma once
#include "../../main/Reference.h"

struct RenderStates {

	RenderStates(float ui__scale = 1.0f)
	:ui_scale(ui__scale) {

	}

	float ui_scale;
};