#include "raylib.h"
#include <vector>
#include "rook.h"

using namespace std;
#define llui long long unsigned int

Rook::Rook(Vector2 pos, int cellsize, const char* imageLocation, char pieceType, int number): Piece(pos, cellsize, pieceType, number)
{
    image = LoadImage(imageLocation);
    ImageResizeNN(&image, 95, 95);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Rook::~Rook()
{
    UnloadTexture(texture);
}

Vector2 tempR = {0, 0};
bool Rook::MoveIsValid(Vector2 from, Vector2 des, Board &Board)
{
    vector<vector<char>> board = Board.board_state;
    if(from.x == des.x || from.y == des.y)
    {
        //left
        if(des.x - from.x < 0)
        {   
            tempR = from;
            while(tempR.x != des.x)
            {
                if(board[int(tempR.y)][int(--tempR.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempR.x == des.x && tempR.y == des.y)
                        return true;
                    else
                        return false;
            } 
            return true;
        }

        // right
        if(des.x - from.x > 0)
        {   
            tempR = from;
            while(tempR.x != des.x)
            {
                if(board[int(tempR.y)][int(++tempR.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempR.x == des.x && tempR.y == des.y)
                        return true;
                    else
                        return false;

            }
            return true;
        }

        //up
        if(des.y - from.y < 0)
        {   
            tempR = from;
            while(tempR.y != des.y)
            {
                cout << "k";
                if(board[int(--tempR.y)][int(tempR.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempR.x == des.x && tempR.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }

        //down
        if(des.y - from.y > 0)
        {   
            tempR = from;
            while(tempR.y != des.y)
            {
                if(board[int(++tempR.y)][int(tempR.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempR.x == des.x && tempR.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }
    }
    else
        return false;
    return false;
}

