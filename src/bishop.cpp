#include "raylib.h"
#include <vector>
#include "bishop.h"

using namespace std;
#define llui long long unsigned int

Bishop::Bishop(Vector2 pos, int cellsize, const char* imageLocation, char pieceType): Piece(pos, cellsize, pieceType)
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
bool Bishop::MoveIsValid(Vector2 from, Vector2 des, vector<vector<char>> board)
{
    if(abs(des.x - from.x) == abs(des.y - from.y))
    {
        //upright
        if(des.x - from.x > 0 && des.y - from.y < 0)
        {
            tempB = from;
            while(tempB.x != des.x)
            {
                if(board[int(--tempB.y)][int(++tempB.x)] != '0')
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
                    return false;
            }
            return true;
        }
    }
    
    return false;
}
