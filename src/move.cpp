#include "raylib.h"
#include <vector>

/*
template <typename T>
void MovePieces(T piece, Vector2 mousePos)
{
    Vector2 temp;
    if((mousePos.x == piece->position.x && mousePos.y == piece->position.y))
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            piece->grabbed = true;
            temp = piece->position;
        }
    }

    if(!IsMouseButtonDown(MOUSE_BUTTON_LEFT) && piece->grabbed)
    {
        if(MoveIsValid(mosPos) && piece->grabbed) 
        {
            piece->position = mousePos;
            piece->grabbed = false;
        }
        else if(piece->grabbed)
        {
            piece->position = temp;
            piece->grabbed = false;
        }
    }

    if(piece->grabbed)
    {
        piece->position.x = float(GetMousePosition().x / cellSize) - 0.5;
        piece->position.y = float(GetMousePosition().y / cellSize) - 0.5;
    }
}
*/