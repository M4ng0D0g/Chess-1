#pragma once
#include "IMoveStrategy.hpp"

namespace chess::piece::strategy {

	class PawnMove : public IMoveStrategy {
	private:
		PawnMove() {}
		~PawnMove() = default;

	public:
		static const PawnMove& instance() {
			static PawnMove inst;
			return inst;
		}
		PawnMove(const PawnMove&) = delete;
		PawnMove& operator=(const PawnMove&) = delete;

		bool isValidMove(Vector2, Vector2, Board &b) const override {
			vector<vector<char>> board = Board.board_state;
			
			if(board[int(des.y)][int(des.x)] == '0')
			{
			if(isupper(board[int(from.y)][int(from.x)]))
			{
				if(from.x == des.x && des.y - from.y == -1){return true;}
				else if(from.x == des.x && des.y - from.y == -2 && from.y == 6){return true;}
				return false;
			}
			else if(islower(board[int(from.y)][int(from.x)]))
			{
				if(from.x == des.x && des.y - from.y == 1){return true;}
				else if(from.x == des.x && des.y - from.y == 2 && from.y == 1){return true;}
				return false;
			}
			}
			return false;
		}
	};
}