#pragma once

#include <iostream>
#include "raylib.h"
#include "board.h"
#include <vector>

Vector2 temp = {0,0};
char type;

template <typename T>
void MovePieces(T piece, Vector2 mousePos, Board &board)
{
    if(piece != nullptr) {
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
        if(piece->MoveIsValid(temp, mousePos, board) && (bool(isupper(piece->piece_type)) != bool(board.turn))) 
        {
            if(board.board_state[int(mousePos.y)][int(mousePos.x)] != '0')
            {
                board.capture_pos = mousePos;
                board.captureType = board.board_state[int(mousePos.y)][int(mousePos.x)];
            }

            piece->position = mousePos;
            piece->grabbed = false;
            board.board_state[int(piece->position.y)][int(piece->position.x)] = piece->piece_type;
            board.board_state[int(temp.y)][int(temp.x)] = '0';
            board.checked = false;

            //Detect if a valid move was made
            //and change the turn if so
            if(board.turn == white) {board.turn = black;}
            else if(board.turn == black) {board.turn = white;}


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
}
