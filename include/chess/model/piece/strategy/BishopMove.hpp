#pragma once
#include "IMoveStrategy.hpp"

namespace chess::piece::strategy {

	class BishopMove : public IMoveStrategy {
	private:
		BishopMove() {}
		~BishopMove() = default;

	public:
		static const BishopMove& instance() {
			static BishopMove inst;
			return inst;
		}
		BishopMove(const BishopMove&) = delete;
		BishopMove& operator=(const BishopMove&) = delete;

		bool isValidMove(const Loc<int>& from, const Loc<int>& dest, Board &b) const override {
			vector<vector<char>> board = b.board_state;

			int deltaX = dest.x - from.x;
			int deltaY = dest.y - from.y;
			
			bool check1 = (abs(deltaX) == abs(deltaY));
			if(!check1) return false;

			

			if(deltaX > 0 && deltaY < 0) {
				//upright
			}

			auto tempB = from;
			while(tempB.x != dest.x) {
				if(board[int(--tempB.y)][int(++tempB.x)] != '0')
					if((bool(islower(board[int(dest.y)][int(dest.x)])) != bool(Board.turn)) && tempB.x == dest.x && tempB.y == dest.y)
						return true;
					else
						return false;
			}
			return true;

			//downright
			if(deltaX > 0 && deltaY > 0)
			{
				tempB = from;
				while(tempB.x != dest.x)
				{
					if(board[int(++tempB.y)][int(++tempB.x)] != '0')
						if((bool(islower(board[int(dest.y)][int(dest.x)])) != bool(Board.turn)) && tempB.x == dest.x && tempB.y == dest.y)
							return true;
						else
							return false;
					
						
				}
				return true;
			}

			//downleft
			if(deltaX < 0 && deltaY > 0)
			{
				tempB = from;
				while(tempB.x != dest.x)
				{
					if(board[int(++tempB.y)][int(--tempB.x)] != '0')
						if((bool(islower(board[int(dest.y)][int(dest.x)])) != bool(Board.turn)) && tempB.x == dest.x && tempB.y == dest.y)
							return true;
						else
							return false;
				}
				return true;
			}

			//upleft
			if(deltaX < 0 && deltaY < 0)
			{
				tempB = from;
				while(tempB.x != dest.x)
				{
					if(board[int(--tempB.y)][int(--tempB.x)] != '0')
						if((bool(islower(board[int(dest.y)][int(dest.x)])) != bool(Board.turn)) && tempB.x == dest.x && tempB.y == dest.y)
							return true;
						else
							return false;
				}
				return true;
			}
		}
	};
}