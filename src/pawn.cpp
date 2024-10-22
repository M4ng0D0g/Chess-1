#include "raylib.h"
#include <vector>
#include "pawn.h"

using namespace std;
#define llui long long unsigned int

Pawn::Pawn(Vector2 pos, int cellsize, const char* imageLocation, char pieceType, int number): Piece(pos, cellsize, pieceType, number)
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

bool Pawn::MoveIsValid(Vector2 from, Vector2 des, Board &Board)
{
    vector<vector<char>> board = Board.board_state;
    
    if(board[int(des.y)][int(des.x)] == '0')
    {
    if(isupper(board[int(from.y)][int(from.x)]))
    {
        if(from.x == des.x && des.y - from.y == -1){return true;}
        else if(from.x == des.x && des.y - from.y == -2 && from.y == 6){return true;}
        return false;
    }
    else if(islower(board[int(from.y)][int(from.x)]))
    {
        if(from.x == des.x && des.y - from.y == 1){return true;}
        else if(from.x == des.x && des.y - from.y == 2 && from.y == 1){return true;}
        return false;
    }
    }
    return false;
}