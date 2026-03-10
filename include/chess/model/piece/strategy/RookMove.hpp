#pragma once
#include "IMoveStrategy.hpp"

namespace chess::model::piece::strategy {

	class RookMove : public IMoveStrategy {
	private:
		RookMove() = default;

	public:
		static const RookMove& instance() {
			static RookMove inst;
			return inst;
		}
		RookMove(const RookMove&) = delete;
		RookMove& operator=(const RookMove&) = delete;

		bool isValidMove(const Loc2<int>& from, const Loc2<int>& dest, const Board& b) const override {
			int deltaX = dest.x - from.x;
			int deltaY = dest.y - from.y;

			// Must move along a rank or file
			if ((deltaX != 0 && deltaY != 0) || (deltaX == 0 && deltaY == 0))
				return false;

			int stepX = (deltaX > 0) ? 1 : (deltaX < 0) ? -1 : 0;
			int stepY = (deltaY > 0) ? 1 : (deltaY < 0) ? -1 : 0;

			// Check path for obstacles
			int x = from.x + stepX;
			int y = from.y + stepY;
			while (x != dest.x || y != dest.y) {
				if (b.boardState[y][x] != nullptr)
					return false;
				x += stepX;
				y += stepY;
			}

			// Destination must be empty or occupied by opponent
			auto& target = b.boardState[dest.y][dest.x];
			if (target == nullptr)
				return true;
			return target->team != b.turn;
		}
	};
}