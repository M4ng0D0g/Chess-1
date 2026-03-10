#pragma once

#include <iostream>
#include "raylib.h"
#include "piece.h"
#include "board.h"
#include <vector>

using namespace std;
#define llui long long unsigned int


class Bishop: public Piece{
public:

    //Initialize piece's position (in tiles)
    Bishop(Vector2, int, const char*, char, int);

    ~Bishop();

    //Check if the move is valid (in tiles)
    bool MoveIsValid(Vector2, Vector2, Board &b);
};