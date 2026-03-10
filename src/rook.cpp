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

}

