#include "raylib.h"
#include <vector>
#include "pawn.h"

using namespace std;
#define llui long long unsigned int

Pawn::Pawn(Vector2 pos, int cellsize, const char* imageLocation, char pieceType): Piece(pos, cellsize, pieceType)
{
    image = LoadImage(imageLocation);
    ImageResizeNN(&image, 95, 95);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Pawn::~Pawn()
{
    UnloadTexture(texture);
}

bool Pawn::MoveIsValid(Vector2 from, Vector2 des, vector<vector<char>> board)
{
    if(from.y == 6 && from.x == des.x)
    {
        if((des.y - from.y == -2 || des.y - from.y == -1) && board[int(des.y)][int(des.x)] == '0')
        {
            return true;
        }
    }
    else if(from.x == des.x && des.y - from.y == -1 && board[int(des.y)][int(des.x)] == '0') return true;
    return false;
    
}