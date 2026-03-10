#pragma once
#include "IMoveStrategy.hpp"

namespace chess::model::piece::strategy {

	class BishopMove : public IMoveStrategy {
	private:
		BishopMove() = default;

	public:
		static const BishopMove& instance() {
			static BishopMove inst;
			return inst;
		}
		BishopMove(const BishopMove&) = delete;
		BishopMove& operator=(const BishopMove&) = delete;

		bool isValidMove(const Loc2<int>& from, const Loc2<int>& dest, const Board& b) const override {
			int deltaX = dest.x - from.x;
			int deltaY = dest.y - from.y;

			// Bishop must move diagonally
			if (abs(deltaX) != abs(deltaY) || deltaX == 0)
				return false;

			int stepX = (deltaX > 0) ? 1 : -1;
			int stepY = (deltaY > 0) ? 1 : -1;

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