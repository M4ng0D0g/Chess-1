#pragma once
#include "IMoveStrategy.hpp"

namespace chess::model::piece::strategy {

	class KingMove : public IMoveStrategy {
	private:
		KingMove() = default;

	public:
		static const KingMove& instance() {
			static KingMove inst;
			return inst;
		}
		KingMove(const KingMove&) = delete;
		KingMove& operator=(const KingMove&) = delete;

		bool isValidMove(const Loc2<int>& from, const Loc2<int>& dest, const Board& b) const override {
			int deltaX = abs(dest.x - from.x);
			int deltaY = abs(dest.y - from.y);

			// King moves at most 1 step in any direction
			if (deltaX > 1 || deltaY > 1 || (deltaX == 0 && deltaY == 0))
				return false;

			// Destination must be empty or occupied by opponent
			auto& target = b.boardState[dest.y][dest.x];
			if (target == nullptr)
				return true;
			return target->team != b.turn;
		}
	};
}