#pragma once
#include "Reference.h"

struct RenderStates {

	RenderStates(float _uiscale = 1.0f)
	:uiScale(_uiscale) {

	}

	float uiScale;
};