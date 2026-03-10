#pragma once
#include "IMoveStrategy.hpp"

namespace chess::model::piece::strategy {

	class PawnMove : public IMoveStrategy {
	private:
		PawnMove() = default;

	public:
		static const PawnMove& instance() {
			static PawnMove inst;
			return inst;
		}
		PawnMove(const PawnMove&) = delete;
		PawnMove& operator=(const PawnMove&) = delete;

		bool isValidMove(const Loc2<int>& from, const Loc2<int>& dest, const Board& b) const override {
			auto& fromPiece = b.boardState[from.y][from.x];
			if (fromPiece == nullptr)
				return false;

			int deltaX = dest.x - from.x;
			int deltaY = dest.y - from.y;
			auto& target = b.boardState[dest.y][dest.x];

			// White moves up (negative y), Black moves down (positive y)
			int direction = (fromPiece->team == Team::White) ? -1 : 1;
			int startRow = (fromPiece->team == Team::White) ? 6 : 1;

			// Forward move (destination must be empty)
			if (deltaX == 0 && target == nullptr) {
				if (deltaY == direction)
					return true;
				// Double move from starting position
				if (deltaY == 2 * direction && from.y == startRow
					&& b.boardState[from.y + direction][from.x] == nullptr)
					return true;
			}

			return false;
		}
	};
}