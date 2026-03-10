#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"

#include "type/PieceType.hpp"

namespace chess::piece {
    using namespace type;

    class Piece {
    protected:
        Texture2D texture;
        Image image;
        

        PieceType _type;
        Style _style;

    public:
        Vector2 position;
        bool grabbed = false; //Check if the piece is being grabbed right now
        bool captured = false;
        int number; //Mark the number of this piece in the list
    
        //right down left up downright downleft upleft upright
        std::vector<Vector2> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};


        //Initialize piece's position (in tiles)
        IPiece(Vector2, int, char, int);
        ~IPiece() = default;

        //Draw
        void Draw();


    };
}

