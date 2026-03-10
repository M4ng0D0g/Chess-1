#pragma once

#include <iostream>

#include "piece.h"
#include "board.h"
#include <vector>

using namespace std;
#define llui long long unsigned int


class King: public Piece{
public:

    //Initialize piece's position (in tiles)
    King(Vector2, int, const char*, char, int);

    ~King();

    //Check if the move is valid (in tiles)
    bool MoveIsValid(Vector2, Vector2, Board &b);
};