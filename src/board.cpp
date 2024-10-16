#include "raylib.h"
#include "board.h"
#include <vector>

using namespace std;

Board::Board(Color Light, Color Dark, int cellsize, int cellcount)
{
    light = Light; dark = Dark;
    cellSize = cellsize;
    cellCount = cellcount;
    vector<char> v(cellCount, '0');
    vector<vector<char>> vec(cellCount, v);
    board_state = vec;
}

void Board::Draw()
{
    Color c = light;
    for(int i=0;i<cellCount;i++)
    {
        for(int j=0;j<cellCount;j++)
        {
            if((i+j) % 2)
                c = dark;
            else
                c = light;
                
            DrawRectangle(i * cellSize, j * cellSize, cellSize, cellSize, c);
        }
    }
}

Vector2 Board::DetectTile(Vector2 mPos)
{
    Vector2 tile = {0,0};
    for(int i=0;i<cellCount;i++)
    {
        if(mPos.x >= i*cellSize && mPos.x <= (i+1)*cellSize)
        {
            tile.x = i;
        }
    }
    for(int j=0;j<cellCount;j++)
    {
        if(mPos.y >= j*cellSize && mPos.y <= (j+1)*cellSize)
        {
            tile.y = j;
        }
    }
    return tile;
}