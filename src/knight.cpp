#include "raylib.h"
#include <vector>
#include "knight.h"

using namespace std;
#define llui long long unsigned int

Knight::Knight(Vector2 pos, int cellsize, const char* imageLocation, char pieceType, int number): Piece(pos, cellsize, pieceType, number)
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

bool Knight::MoveIsValid(Vector2 from, Vector2 des, Board &Board)
{
    vector<vector<char>> board = Board.board_state;

    if(((abs(des.x - from.x) == 2 && abs(des.y - from.y) == 1) || (abs(des.x - from.x) == 1 && abs(des.y - from.y) == 2))
        && ((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) || board[int(des.y)][int(des.x)] == '0'))
    {
        return true;
    }   
    else
        return false;
    

}
