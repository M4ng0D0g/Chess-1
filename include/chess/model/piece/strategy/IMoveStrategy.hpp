#pragma once
#include "chess/enums/Team.hpp"
#include "chess/board/Board.hpp"
#include "raylib.h"
#include "chess/utils/Unit.hpp"

namespace chess::piece::strategy {
	using namespace board;
	using namespace utils;

	class IMoveStrategy {
	public:
		virtual ~IMoveStrategy() = default;

		virtual bool isValidMove(const Loc<int>&, const Loc<int>&, Board &b) const = 0;
	};
}