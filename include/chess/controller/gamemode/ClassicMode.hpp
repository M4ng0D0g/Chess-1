#pragma once
#include "IGamemode.hpp"


namespace chess::controller::gamemode {
	
	class ClassicMode : public IGamemode {
	private:
		ClassicMode() {};
		~ClassicMode() = default;

		const Size2 _cellSize{100, 100};
		const Size2 _cellCount{8, 8};
		const String _title = "Chess(Classic)";

	public:
		static ClassicMode& inst() {
			static ClassicMode inst;
			return inst;
		}

		const Size2& getCellSize() const override {
			return _cellSize;
		}
		const Size2& getCellCount() const override {
			return _cellCount;
		}
		const String& getTitle() const override {
			return _title;
		}
		

		
		
		void init() {
			//Initialize Board & Piece lists
			Board board = Board(light, dark, cellSize, cellCount);
			vector<Pawn*> Wp_list(8); vector<Pawn*> Bp_list(8);
			vector<Knight*> Wn_list(2); vector<Knight*> Bn_list(2);
			vector<Rook*> Wr_list(2); vector<Rook*> Br_list(2);
			vector<Bishop*> Wb_list(2); vector<Bishop*> Bb_list(2);

			 //Initialize Pieces' position
			Vector2 ini_pos = {0,0}; 
			
			//Initialize Pawns
			ini_pos = {0,6};
			for(llui i=0;i<Wp_list.size();i++)
			{
				ini_pos.x = float(i);
				Pawn* pawn = new Pawn(ini_pos, cellSize, WpawnImage, 'P', int(i));
				board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'P';
				Wp_list[i] = pawn;
			}
			ini_pos = {0,1};
			for(llui i=0;i<Bp_list.size();i++)
			{
				ini_pos.x = float(i);
				Pawn* pawn = new Pawn(ini_pos, cellSize, BpawnImage, 'p', int(i));
				board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'p';
				Bp_list[i] = pawn;
			}

			//Initialize Knights
			ini_pos = {1,7};
			Knight* Wknight1 = new Knight(ini_pos, cellSize, WknightImage, 'N', 0); Wn_list[0] = Wknight1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'N';
			ini_pos = {6,7};
			Knight* Wknight2 = new Knight(ini_pos, cellSize, WknightImage, 'N', 1); Wn_list[1] = Wknight2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'N';
			ini_pos = {1,0};
			Knight* Bknight1 = new Knight(ini_pos, cellSize, BknightImage, 'n', 0); Bn_list[0] = Bknight1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'n';
			ini_pos = {6,0};
			Knight* Bknight2 = new Knight(ini_pos, cellSize, BknightImage, 'n', 1); Bn_list[1] = Bknight2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'n';
			
			//Initialize Rooks
			ini_pos = {0,7};
			Rook* Wrook1 = new Rook(ini_pos, cellSize, WrookImage, 'R', 0); Wr_list[0] = Wrook1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'R';
			ini_pos = {7,7};
			Rook* Wrook2 = new Rook(ini_pos, cellSize, WrookImage, 'R', 1); Wr_list[1] = Wrook2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'R';
			ini_pos = {0,0};
			Rook* Brook1 = new Rook(ini_pos, cellSize, BrookImage, 'r', 0); Br_list[0] = Brook1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'r';
			ini_pos = {7,0};
			Rook* Brook2 = new Rook(ini_pos, cellSize, BrookImage, 'r', 1); Br_list[1] = Brook2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'r';

			//Initialize Bishops
			ini_pos = {2,7};
			Bishop* Wbishop1 = new Bishop(ini_pos, cellSize, WbishopImage, 'B', 0); Wb_list[0] = Wbishop1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'B';
			ini_pos = {5,7};
			Bishop* Wbishop2 = new Bishop(ini_pos, cellSize, WbishopImage, 'B', 1); Wb_list[1] = Wbishop2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'B';
			ini_pos = {2,0};
			Bishop* Bbishop1 = new Bishop(ini_pos, cellSize, BbishopImage, 'b', 0); Bb_list[0] = Bbishop1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'b';
			ini_pos = {5,0};
			Bishop* Bbishop2 = new Bishop(ini_pos, cellSize, BbishopImage, 'b', 1); Bb_list[1] = Bbishop2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'b';


			//Initialize Kings
			ini_pos = {4,7};
			King* Wking = new King(ini_pos, cellSize, WkingImage, 'K', 0); board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'K';
			ini_pos = {4,0};
			King* Bking = new King(ini_pos, cellSize, BkingImage, 'k', 0); board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'k';


			//Initialize Queens
			ini_pos = {3,7};
			Queen* Wqueen = new Queen(ini_pos, cellSize, WqueenImage, 'Q', 0); board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'Q';
			ini_pos = {3,0};
			Queen* Bqueen = new Queen(ini_pos, cellSize, BqueenImage, 'q', 0); board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'q';

		}

	
	};
}