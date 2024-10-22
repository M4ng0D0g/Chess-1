#include "raylib.h"
#include <vector>
#include "bishop.h"

using namespace std;
#define llui long long unsigned int

Bishop::Bishop(Vector2 pos, int cellsize, const char* imageLocation, char pieceType, int number): Piece(pos, cellsize, pieceType, number)
{
    image = LoadImage(imageLocation);
    ImageResizeNN(&image, 95, 95);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Bishop::~Bishop()
{
    UnloadTexture(texture);
}

Vector2 tempB = {0, 0};
bool Bishop::MoveIsValid(Vector2 from, Vector2 des, Board &Board)
{
    vector<vector<char>> board = Board.board_state;
    if(abs(des.x - from.x) == abs(des.y - from.y))
    {
        //upright
        if(des.x - from.x > 0 && des.y - from.y < 0)
        {
            tempB = from;
            while(tempB.x != des.x)
            {
                if(board[int(--tempB.y)][int(++tempB.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempB.x == des.x && tempB.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }

        //downright
        if(des.x - from.x > 0 && des.y - from.y > 0)
        {
            tempB = from;
            while(tempB.x != des.x)
            {
                if(board[int(++tempB.y)][int(++tempB.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempB.x == des.x && tempB.y == des.y)
                        return true;
                    else
                        return false;
                
                    
            }
            return true;
        }

        //downleft
        if(des.x - from.x < 0 && des.y - from.y > 0)
        {
            tempB = from;
            while(tempB.x != des.x)
            {
                if(board[int(++tempB.y)][int(--tempB.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempB.x == des.x && tempB.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }

        //upleft
        if(des.x - from.x < 0 && des.y - from.y < 0)
        {
            tempB = from;
            while(tempB.x != des.x)
            {
                if(board[int(--tempB.y)][int(--tempB.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempB.x == des.x && tempB.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }
    }
    
    return false;
}
