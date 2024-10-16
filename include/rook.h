#pragma once

#include <iostream>
#include "raylib.h"
#include "piece.h"
#include <vector>

using namespace std;
#define llui long long unsigned int

class Rook: public Piece{
public:

    //Initialize piece's position (in tiles)
    Rook(Vector2, int, const char*, char);

    ~Rook();
    
    //Check if the move is valid (in tiles)
    bool MoveIsValid(Vector2, Vector2, vector<vector<char>> board);
};