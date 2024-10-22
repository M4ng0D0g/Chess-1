#pragma once

#include <iostream>
#include "raylib.h"
#include <vector>

using namespace std;
#define llui long long unsigned int


class Piece{
public:
    Vector2 position;
    char piece_type;
    bool grabbed = false; //Check if the piece is being grabbed right now
    bool captured = false;
    int number; //Mark the number of this piece in the list
   
    //right down left up downright downleft upleft upright
    vector<Vector2> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};


    //Initialize piece's position (in tiles)
    Piece(Vector2, int, char, int);

    ~Piece();

    //Draw
    void Draw();

protected:
    Texture2D texture;
    Image image;
    int cellSize = 0;
};