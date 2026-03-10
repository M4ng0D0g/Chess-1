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