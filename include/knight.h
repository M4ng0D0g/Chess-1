#pragma once

#include <iostream>
#include "raylib.h"
#include "piece.h"
#include "board.h"
#include <vector>

using namespace std;
#define llui long long unsigned int


class Knight: public Piece{
public:

    //Initialize piece's position (in tiles)
    Knight(Vector2, int, const char*, char, int);

    ~Knight();

    //Check if the move is valid (in tiles)
    bool MoveIsValid(Vector2, Vector2, Board &b);
};