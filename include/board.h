#pragma once

#include "raylib.h"
#include <vector>

using namespace std;

enum state
{
    white, black
};

class Board{
public:
    Color light, dark;
    int cellSize, cellCount;
    vector<vector<char>> board_state;
    state turn = white;
    bool moved = false;
    bool inCheck = false;
    bool checked = false;
    Vector2 capture_pos = {-1, -1};
    char captureType = '0';

    //Draw a grid with cellCount * cellCount, with each tile
    //is the size of cellSize * cellSize
    Board(Color light, Color dark, int cellSize, int cellCount);
    
    //Draw
    void Draw();
    
    //Detect which tile the mouse is in, with (0,0) being the top left
    //tile, and increase in x going right, increase in y going down
    Vector2 DetectTile(Vector2 mPos);
};

