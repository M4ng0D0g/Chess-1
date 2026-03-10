#pragma once
#include "IMoveStrategy.hpp"

namespace chess::piece::strategy {
	using namespace board;

	class KingMove : public IMoveStrategy {
	private:
		KingMove() {}
		~KingMove() = default;

	public:
		static const KingMove& instance() {
			static KingMove inst;
			return inst;
		}
		KingMove(const KingMove&) = delete;
		KingMove& operator=(const KingMove&) = delete;

		bool isValidMove(const Loc<int>& from, const Loc<int>& dest, Board &b) const override {
			std::vector<std::vector<char>> board = b.board_state;

			bool check1 = (abs(dest.x - from.x) == 1 && abs(dest.y - from.y) == 1);
			bool check2 = (abs(dest.x - from.x) == 1 && dest.y == from.y);
			bool check3 = (abs(dest.y - from.y) == 1 && dest.x == from.x);
			bool check4 = (bool(islower(board[int(dest.y)][int(dest.x)])) != bool(b.turn));
			bool check5 = (board[int(dest.y)][int(dest.x)] == '0');

			if((check1 || check2 || check3) && (check4 || check5)) return true;
			else return false;
		}
	};
}