#pragma once
#include "IMoveStrategy.hpp"

namespace chess::piece::strategy {

	class KnightMove : public IMoveStrategy {
	private:
		KnightMove() {}
		~KnightMove() = default;

	public:
		static const KnightMove& instance() {
			static KnightMove inst;
			return inst;
		}
		KnightMove(const KnightMove&) = delete;
		KnightMove& operator=(const KnightMove&) = delete;

		bool isValidMove(Vector2, Vector2, Board &b) const override {
			vector<vector<char>> board = Board.board_state;

			if(((abs(des.x - from.x) == 2 && abs(des.y - from.y) == 1) || (abs(des.x - from.x) == 1 && abs(des.y - from.y) == 2))
				&& ((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) || board[int(des.y)][int(des.x)] == '0'))
			{
				return true;
			}   
			else
				return false;
			

		}
	};
}