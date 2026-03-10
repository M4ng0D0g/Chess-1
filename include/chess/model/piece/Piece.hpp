#pragma once

#include "chess/utils/Unit.hpp"
#include "chess/model/enums/Team.hpp"

namespace chess::model::piece {
    using namespace enums;
    using namespace utils;

    class PieceType; // forward declaration

    class Piece {
    public:
        const PieceType& type;
        Team team;
        Loc2<int> position;
        bool captured = false;

        Piece(const PieceType& t, Team tm, Loc2<int> pos)
            : type(t), team(tm), position(pos) {}
        ~Piece() = default;
    };
}

