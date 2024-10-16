#include "raylib.h"
#include <vector>
#include "knight.h"

using namespace std;
#define llui long long unsigned int

Knight::Knight(Vector2 pos, int cellsize, const char* imageLocation, char pieceType): Piece(pos, cellsize, pieceType)
{
    image = LoadImage(imageLocation);
    ImageResizeNN(&image, 95, 95);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Knight::~Knight()
{
    UnloadTexture(texture);
}

bool Knight::MoveIsValid(Vector2 from, Vector2 des, vector<vector<char>> board)
{
    if((abs(des.x - from.x) == 2 && abs(des.y - from.y) == 1) || (abs(des.x - from.x) == 1 && abs(des.y - from.y) == 2))
    {
        if(board[int(des.y)][int(des.x)] == '0')
            return true;
        else    
            return false;
    }   
    else
        return false;
    
}
