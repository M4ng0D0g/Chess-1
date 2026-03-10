#pragma once
#include "IMoveStrategy.hpp"

namespace chess::piece::strategy {

	class RookMove : public IMoveStrategy {
	private:
		RookMove() {}
		~RookMove() = default;

	public:
		static const RookMove& instance() {
			static RookMove inst;
			return inst;
		}
		RookMove(const RookMove&) = delete;
		RookMove& operator=(const RookMove&) = delete;

		bool isValidMove(Vector2, Vector2, Board &b) const override {
			vector<vector<char>> board = Board.board_state;
			if(from.x == des.x || from.y == des.y)
			{
				//left
				if(des.x - from.x < 0)
				{   
					tempR = from;
					while(tempR.x != des.x)
					{
						if(board[int(tempR.y)][int(--tempR.x)] != '0')
							if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempR.x == des.x && tempR.y == des.y)
								return true;
							else
								return false;
					} 
					return true;
				}

				// right
				if(des.x - from.x > 0)
				{   
					tempR = from;
					while(tempR.x != des.x)
					{
						if(board[int(tempR.y)][int(++tempR.x)] != '0')
							if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempR.x == des.x && tempR.y == des.y)
								return true;
							else
								return false;

					}
					return true;
				}

				//up
				if(des.y - from.y < 0)
				{   
					tempR = from;
					while(tempR.y != des.y)
					{
						if(board[int(--tempR.y)][int(tempR.x)] != '0')
							if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempR.x == des.x && tempR.y == des.y)
								return true;
							else
								return false;
					}
					return true;
				}

				//down
				if(des.y - from.y > 0)
				{   
					tempR = from;
					while(tempR.y != des.y)
					{
						if(board[int(++tempR.y)][int(tempR.x)] != '0')
							if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempR.x == des.x && tempR.y == des.y)
								return true;
							else
								return false;
					}
					return true;
				}
			}
			else
				return false;
			return false;
		}
	};
}