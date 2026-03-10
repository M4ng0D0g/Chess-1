#pragma once
#include "gamemode/IGamemode.hpp"
#include "chess/view/Theme.hpp"
#include "chess/model/board/Board.hpp"

namespace chess::controller {
	using namespace chess::utils;
	using namespace chess::model;
	using namespace chess::view;

	class ChessController {
	private:
		UPtr<gamemode::IGamemode> _mode;
		Theme& _theme;
		board::Board _board;

	public:
		ChessController(
			UPtr<gamemode::IGamemode> mode,
			Theme& theme
		) : _mode(std::move(mode)), _theme(theme),
		    _board(_mode->getCellCount(), _mode->getCellSize(), theme) {}

		Size2 requiredWindowSize() const {
			return {_board.cellCount.x * _board.cellSize.x,
			        _board.cellCount.y * _board.cellSize.y};
		}

		const char* title() const {
			return _mode->getTitle().c_str();
		}

		void init() {
			_mode->init(_board);
		}

		void update() {
			_mode->update(_board);
		}

		void draw() {
			ClearBackground(_theme.getLightColor());
			_board.draw();
			_mode->drawPieces(_board);
		}
	};

	using Chess = ChessController;
}
