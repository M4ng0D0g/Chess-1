#pragma once
#include "gamemode/IGamemode.hpp"
#include "chess/view/Theme.hpp"

namespace chess::controller {
	using namespace utils;
	using namespace view;

	using Chess = ChessController;
	class ChessController {
	private:
		UPtr<gamemode::IGamemode> _mode;
		Theme& _theme;

	public:
		ChessController(
			UPtr<gamemode::IGamemode> mode,
			Theme& theme
		) : _mode(std::move(mode)), _theme(theme) {}

		const Size2 requiredWindowSize() {
			auto cellCount = _mode->getCellCount();
			auto cellSize = _mode->getCellSize();
			return {cellCount.x * cellSize.x, cellCount.y * cellSize.y};
		}

		const String title() {
			return _mode->getTitle();
		}

		void init() {
			_mode->init();
		}


	};
}