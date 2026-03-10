#pragma once
#include <string>
#include <vector>
#include "chess/model/board/Board.hpp"
#include "chess/model/piece/strategy/IMoveStrategy.hpp"
#include "chess/model/piece/strategy/KingMove.hpp"
#include "chess/model/piece/strategy/RookMove.hpp"
#include "chess/model/piece/strategy/BishopMove.hpp"
#include "chess/model/piece/strategy/KnightMove.hpp"
#include "chess/model/piece/strategy/PawnMove.hpp"
#include "chess/utils/Unit.hpp"

namespace chess::model::piece {
	using namespace board;
	using namespace enums;
	using namespace utils;
	
	class PieceType {
	private:
		explicit PieceType(
			const std::string& name,
			char baseSymbol,
			std::vector<const strategy::IMoveStrategy*> strategies
		) : _name(name), _baseSymbol(baseSymbol), _moveStrategies(std::move(strategies)) {}

		std::string _name;
		char _baseSymbol;
		std::vector<const strategy::IMoveStrategy*> _moveStrategies;
		
	public:
		static const PieceType& KING() {
			static PieceType inst("king", 'K', {&strategy::KingMove::instance()});
			return inst;
		}
		static const PieceType& QUEEN() {
			static PieceType inst("queen", 'Q', {&strategy::RookMove::instance(), &strategy::BishopMove::instance()});
			return inst;
		}
		static const PieceType& ROOK() {
			static PieceType inst("rook", 'R', {&strategy::RookMove::instance()});
			return inst;
		}
		static const PieceType& BISHOP() {
			static PieceType inst("bishop", 'B', {&strategy::BishopMove::instance()});
			return inst;
		}
		static const PieceType& KNIGHT() {
			static PieceType inst("knight", 'N', {&strategy::KnightMove::instance()});
			return inst;
		}
		static const PieceType& PAWN() {
			static PieceType inst("pawn", 'P', {&strategy::PawnMove::instance()});
			return inst;
		}

		PieceType(const PieceType&) = delete;
		PieceType& operator=(const PieceType&) = delete;

		char getBaseSymbol() const { return _baseSymbol; }
		const std::string& getName() const { return _name; }

		bool checkMove(const Loc2<int>& from, const Loc2<int>& dest, const Board& board) const {
			for (const auto* move : _moveStrategies) {
				if (move->isValidMove(from, dest, board)) return true;
			}
			return false;
		}
	};
}