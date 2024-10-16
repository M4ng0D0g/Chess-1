#include "raylib.h"
#include <vector>
#include "rook.h"

using namespace std;
#define llui long long unsigned int

Rook::Rook(Vector2 pos, int cellsize, const char* imageLocation, char pieceType): Piece(pos, cellsize, pieceType)
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

bool Rook::MoveIsValid(Vector2 from, Vector2 des, vector<vector<char>> board)
{
    if(from.x == des.x || from.y == des.y)
    {
        //left
        if(des.x - from.x < 0)
        {   
            Vector2 temp = from;
            while(temp.x != des.x)
            {
                if(board[int(temp.y)][int(temp.x += dir[2].x)] != '0')
                    return false;
            } 
            return true;
        }

        // right
        if(des.x - from.x > 0)
        {   
            Vector2 temp = from;
            while(temp.x != des.x)
            {
                if(board[int(temp.y)][int(temp.x += dir[0].x)] != '0')
                    return false;

            }
            return true;
        }

        //up
        if(des.y - from.y < 0)
        {   
            Vector2 temp = from;
            while(temp.y != des.y)
            {
                if(board[int(temp.y += dir[3].y)][int(temp.x)] != '0')
                    return false;
            }
            return true;
        }

        //down
        if(des.y - from.y > 0)
        {   
            Vector2 temp = from;
            while(temp.y != des.y)
            {
                if(board[int(temp.y += dir[1].y)][int(temp.x)] != '0')
                    return false;
            }
            return true;
        }
    }
    else
        return false;
    return false;
}