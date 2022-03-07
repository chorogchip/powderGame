#pragma once

namespace ch {

	enum class EnumActionResult {

		SUCCEED,
		FAILED,

		SKIPPED,
		APPLIED,

	};

	constexpr bool toSkip(EnumActionResult res) {
		return res == EnumActionResult::SKIPPED || res == EnumActionResult::APPLIED;
	}

};
