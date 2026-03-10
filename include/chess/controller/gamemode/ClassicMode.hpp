#pragma once
#include "IGamemode.hpp"
#include "chess/model/piece/Piece.hpp"
#include "chess/model/piece/PieceType.hpp"
#include "chess/model/manager/TextureManager.hpp"

namespace chess::controller::gamemode {
	using namespace chess::model;
	using namespace chess::model::board;
	using namespace chess::model::piece;
	using namespace chess::model::enums;
	using namespace chess::model::manager;
	using namespace chess::utils;

	class ClassicMode : public IGamemode {
	private:
		const Size2 _cellSize{100, 100};
		const Size2 _cellCount{8, 8};
		const String _title = "Chess(Classic)";

		Loc2<int> _selected{-1, -1};
		bool _hasSelection = false;

	public:
		ClassicMode() = default;
		~ClassicMode() override = default;

		const Size2& getCellSize() const override { return _cellSize; }
		const Size2& getCellCount() const override { return _cellCount; }
		const String& getTitle() const override { return _title; }

		void init(Board& board) override {
			auto place = [&](int x, int y, const PieceType& type, Team team) {
				board.boardState[y][x] = std::make_shared<Piece>(type, team, Loc2<int>{x, y});
			};

			// White pieces (bottom)
			for (int i = 0; i < 8; ++i)
				place(i, 6, PieceType::PAWN(), Team::White);
			place(0, 7, PieceType::ROOK(),   Team::White);
			place(1, 7, PieceType::KNIGHT(), Team::White);
			place(2, 7, PieceType::BISHOP(), Team::White);
			place(3, 7, PieceType::QUEEN(),  Team::White);
			place(4, 7, PieceType::KING(),   Team::White);
			place(5, 7, PieceType::BISHOP(), Team::White);
			place(6, 7, PieceType::KNIGHT(), Team::White);
			place(7, 7, PieceType::ROOK(),   Team::White);

			// Black pieces (top)
			for (int i = 0; i < 8; ++i)
				place(i, 1, PieceType::PAWN(), Team::Black);
			place(0, 0, PieceType::ROOK(),   Team::Black);
			place(1, 0, PieceType::KNIGHT(), Team::Black);
			place(2, 0, PieceType::BISHOP(), Team::Black);
			place(3, 0, PieceType::QUEEN(),  Team::Black);
			place(4, 0, PieceType::KING(),   Team::Black);
			place(5, 0, PieceType::BISHOP(), Team::Black);
			place(6, 0, PieceType::KNIGHT(), Team::Black);
			place(7, 0, PieceType::ROOK(),   Team::Black);
		}

		void update(Board& board) override {
			if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return;

			auto tile = board.detectTile(GetMousePosition());

			if (!_hasSelection) {
				auto& piece = board.boardState[tile.y][tile.x];
				if (piece && piece->team == board.turn) {
					_selected = tile;
					_hasSelection = true;
				}
			} else {
				auto& src = board.boardState[_selected.y][_selected.x];
				if (src && src->type.checkMove(_selected, tile, board)) {
					board.boardState[tile.y][tile.x] = std::move(src);
					board.boardState[tile.y][tile.x]->position = tile;
					board.turn = (board.turn == Team::White) ? Team::Black : Team::White;
				}
				_hasSelection = false;
			}
		}

		void drawPieces(const Board& board) override {
			auto& texMgr = TextureManager::instance();
			for (int y = 0; y < (int)board.cellCount.y; ++y) {
				for (int x = 0; x < (int)board.cellCount.x; ++x) {
					auto& piece = board.boardState[y][x];
					if (!piece) continue;
					const Texture2D& tex = texMgr.getTexture(
						board.theme, piece->type, piece->team
					);
					DrawTexture(tex,
						x * (int)board.cellSize.x,
						y * (int)board.cellSize.y,
						WHITE
					);
				}
			}

			// Highlight selected tile
			if (_hasSelection) {
				DrawRectangleLines(
					_selected.x * (int)board.cellSize.x,
					_selected.y * (int)board.cellSize.y,
					(int)board.cellSize.x,
					(int)board.cellSize.y,
					YELLOW
				);
			}
		}
	};
}