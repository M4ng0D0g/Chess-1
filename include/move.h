#pragma once

#include "raylib.h"
#include "board.h"
#include <vector>

Vector2 temp = {0,0};
char type;

template <typename T>
void MovePieces(T piece, Vector2 mousePos, Board &board)
{
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
        if(piece->MoveIsValid(temp, mousePos, board.board_state) && (isupper(piece->piece_type) ^ board.turn)) 
        {
            piece->position = mousePos;
            piece->grabbed = false;
            board.board_state[int(piece->position.y)][int(piece->position.x)] = piece->piece_type;
            board.board_state[int(temp.y)][int(temp.x)] = '0';
            board.moved = true;

            for(auto &n : board.board_state)
            {
                for(auto &p : n)
                    cout << p << " ";
                cout << "\n";
            }
            cout << "\n";
            cout << board.turn;
            cout << "\n";
        }
        else
        {
            piece->position = temp;
            piece->grabbed = false;
        }
    }

    if(piece->grabbed)
    {
        piece->position.x = float(GetMousePosition().x / cellSize) - 0.5f;
        piece->position.y = float(GetMousePosition().y / cellSize) - 0.5f;
    }
}
