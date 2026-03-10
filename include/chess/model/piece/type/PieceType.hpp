#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Style.hpp"
#include "Team.hpp"
#include "chess/board/Board.hpp"
#include "chess/utils/Unit.hpp"
#include "chess/piece/strategy/IMoveStrategy.hpp"
#include "chess/piece/strategy/KingMove.hpp"
#include "chess/piece/strategy/RookMove.hpp"
#include "chess/piece/strategy/BishopMove.hpp"
#include "chess/piece/strategy/KnightMove.hpp"
#include "chess/piece/strategy/PawnMove.hpp"


namespace chess::piece::type {
	using namespace board;
	using namespace enums;
	using namespace utils;
	
	class PieceType {
	private:
		explicit PieceType(
			char baseSymbol
		) : _baseSymbol(baseSymbol) {}

		char _baseSymbol;
		std::vector<UPtr<strategy::IMoveStrategy>> _moveStrategies;

		template<typename... Strategies>
		void addStrategies() {
			( _moveStrategies.emplace_back(std::make_unique<Strategies>()), ... );
		}
		
	public:
		static const PieceType& KING() {
			static PieceType inst('K');
			static bool init = false;
			if (!init) {
				inst.addStrategies<strategy::KingMove>();
				init = true;
			}
			return inst;
		}
		static const PieceType& QUEEN() {
			static PieceType inst('Q');
			static bool init = false;
			if (!init) {
				inst.addStrategies<strategy::RookMove, strategy::BishopMove>();
				init = true;
			}
			return inst;
		}
		static const PieceType& ROOK() {
			static PieceType inst('R');
			static bool init = false;
			if (!init) {
				inst.addStrategies<strategy::RookMove>();
				init = true;
			}
			return inst;
		}
		static const PieceType& BISHOP() {
			static PieceType inst('B');
			static bool init = false;
			if (!init) {
				inst.addStrategies<strategy::BishopMove>();
				init = true;
			}
			return inst;
		}
		static const PieceType& KNIGHT() {
			static PieceType inst('N');
			static bool init = false;
			if (!init) {
				inst.addStrategies<strategy::KnightMove>();
				init = true;
			}
			return inst;
		}
		static const PieceType& PAWN() {
			static PieceType inst('P');
			static bool init = false;
			if (!init) {
				inst.addStrategies<strategy::PawnMove>();
				init = true;
			}
			return inst;
		}

		PieceType(const PieceType&) = delete;
		PieceType& operator=(const PieceType&) = delete;
		bool operator==(const PieceType& other) { return *this == other; }
		bool operator!=(const PieceType& other) { return !(*this == other); }

		char getBaseSymbol() const { return _baseSymbol; }

		bool checkMove(int fx, int fy, int tx, int ty, Team team, const Board& b) const {
			return _moveStrategy->isValidMove(fx, fy, tx, ty, team, b);
		}
	};
}