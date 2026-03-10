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

}