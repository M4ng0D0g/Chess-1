#include "raylib.h"
#include <vector>
#include "piece.h"

using namespace std;
#define llui long long unsigned int

Piece::Piece(Vector2 pos, int cellsize, char pieceType, int n)
{
    position = pos;
    cellSize = cellsize;
    piece_type = pieceType;
    number = n;
}

Piece::~Piece()
{
    UnloadTexture(texture);
}

void Piece::Draw()
{
    DrawTexture(texture, position.x*cellSize, position.y*cellSize, WHITE);
}
