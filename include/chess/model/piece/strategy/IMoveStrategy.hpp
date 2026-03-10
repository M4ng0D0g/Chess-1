#pragma once
#include "chess/model/enums/Team.hpp"
#include "chess/model/board/Board.hpp"
#include "raylib.h"
#include "chess/utils/Unit.hpp"

namespace chess::model::piece::strategy {
	using namespace board;
	using namespace utils;
	using namespace enums;

	class IMoveStrategy {
	public:
		virtual ~IMoveStrategy() = default;

		virtual bool isValidMove(const Loc2<int>& from, const Loc2<int>& dest, const Board& b) const = 0;
	};
}