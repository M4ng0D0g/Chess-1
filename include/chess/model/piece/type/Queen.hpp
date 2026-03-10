#pragma once

#include <iostream>
#include "raylib.h"
#include "piece.h"
#include "board.h"
#include <vector>

using namespace std;
#define llui long long unsigned int


class Queen : public Piece{
public:
    
    //Initialize piece's position (in tiles)
    Queen(Vector2, int, const char*, char, int);

    ~Queen();

    //Check if the move is valid (in tiles)
    bool MoveIsValid(Vector2, Vector2, Board &board);
};

