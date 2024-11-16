#include "raylib.h"
#include <vector>
#include "queen.h"

using namespace std;
#define llui long long unsigned int

Queen::Queen(Vector2 pos, int cellsize, const char* imageLocation, char pieceType, int number): Piece(pos, cellsize, pieceType, number)
{
    image = LoadImage(imageLocation);
    ImageResizeNN(&image, 95, 95);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Queen::~Queen()
{
    UnloadTexture(texture);
}

Vector2 tempQ = {0, 0};
bool Queen::MoveIsValid(Vector2 from, Vector2 des, Board &Board)
{
    vector<vector<char>> board = Board.board_state;

    //upright
    if(abs(des.x - from.x) == abs(des.y - from.y))
    {
        if(des.x - from.x > 0 && des.y - from.y < 0)
        {
            tempQ = from;
            while(tempQ.x != des.x)
            {
                if(board[int(--tempQ.y)][int(++tempQ.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempQ.x == des.x && tempQ.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }

        //downright
        if(des.x - from.x > 0 && des.y - from.y > 0)
        {
            tempQ = from;
            while(tempQ.x != des.x)
            {
                if(board[int(++tempQ.y)][int(++tempQ.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempQ.x == des.x && tempQ.y == des.y)
                        return true;
                    else
                        return false;
                
                    
            }
            return true;
        }

        //downleft
        if(des.x - from.x < 0 && des.y - from.y > 0)
        {
            tempQ = from;
            while(tempQ.x != des.x)
            {
                if(board[int(++tempQ.y)][int(--tempQ.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempQ.x == des.x && tempQ.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }

        //upleft
        if(des.x - from.x < 0 && des.y - from.y < 0)
        {
            tempQ = from;
            while(tempQ.x != des.x)
            {
                if(board[int(--tempQ.y)][int(--tempQ.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempQ.x == des.x && tempQ.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }
    }
    
    if(from.x == des.x || from.y == des.y)
    {
        //left
        if(des.x - from.x < 0)
        {   
            tempQ = from;
            while(tempQ.x != des.x)
            {
                if(board[int(tempQ.y)][int(--tempQ.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempQ.x == des.x && tempQ.y == des.y)
                        return true;
                    else
                        return false;
            } 
            return true;
        }

        // right
        if(des.x - from.x > 0)
        {   
            tempQ = from;
            while(tempQ.x != des.x)
            {
                if(board[int(tempQ.y)][int(++tempQ.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempQ.x == des.x && tempQ.y == des.y)
                        return true;
                    else
                        return false;

            }
            return true;
        }

        //up
        if(des.y - from.y < 0)
        {   
            tempQ = from;
            while(tempQ.y != des.y)
            {
                cout << "k";
                if(board[int(--tempQ.y)][int(tempQ.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempQ.x == des.x && tempQ.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }

        //down
        if(des.y - from.y > 0)
        {   
            tempQ = from;
            while(tempQ.y != des.y)
            {
                if(board[int(++tempQ.y)][int(tempQ.x)] != '0')
                    if((bool(islower(board[int(des.y)][int(des.x)])) != bool(Board.turn)) && tempQ.x == des.x && tempQ.y == des.y)
                        return true;
                    else
                        return false;
            }
            return true;
        }
    }

    return false;
}
