#pragma once
#include "chess/utils/Unit.hpp"
#include "chess/model/board/Board.hpp"

namespace chess::controller::gamemode {
	using namespace chess::utils;
	using namespace chess::model::board;

	class IGamemode {
	public:
		virtual ~IGamemode() = default;

		virtual const Size2& getCellSize() const = 0;
		virtual const Size2& getCellCount() const = 0;
		virtual const String& getTitle() const = 0;

		virtual void init(Board& board) = 0;
		virtual void update(Board& board) = 0;
		virtual void drawPieces(const Board& board) = 0;
	};
}