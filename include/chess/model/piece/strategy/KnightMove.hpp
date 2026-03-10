#pragma once
#include "IMoveStrategy.hpp"

namespace chess::model::piece::strategy {

	class KnightMove : public IMoveStrategy {
	private:
		KnightMove() = default;

	public:
		static const KnightMove& instance() {
			static KnightMove inst;
			return inst;
		}
		KnightMove(const KnightMove&) = delete;
		KnightMove& operator=(const KnightMove&) = delete;

		bool isValidMove(const Loc2<int>& from, const Loc2<int>& dest, const Board& b) const override {
			int deltaX = abs(dest.x - from.x);
			int deltaY = abs(dest.y - from.y);

			// L-shape: 2+1 or 1+2
			if (!((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2)))
				return false;

			// Destination must be empty or occupied by opponent
			auto& target = b.boardState[dest.y][dest.x];
			if (target == nullptr)
				return true;
			return target->team != b.turn;
		}
	};
}