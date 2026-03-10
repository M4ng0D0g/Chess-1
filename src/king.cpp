#include "raylib.h"
#include <vector>
#include "king.h"

using namespace std;
#define llui long long unsigned int

King::King(Vector2 pos, int cellsize, const char* imageLocation, char pieceType, int number): Piece(pos, cellsize, pieceType, number)
{
    image = LoadImage(imageLocation);
    ImageResizeNN(&image, 95, 95);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

King::~King()
{
    UnloadTexture(texture);
}

