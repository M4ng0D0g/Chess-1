#include <iostream>
#include <vector>
#include "raylib.h"
#include "chess/controller/ChessController.hpp"
#include "chess/controller/gamemode/ClassicMode.hpp"


int main() {
    using namespace chess::controller;
    Chess game(std::make_unique<gamemode::ClassicMode>());
    Size2 WindowSize = game.requiredWindowSize();

    InitWindow(WindowSize.x, WindowSize.y, game.title());
    SetTargetFPS(60);

   
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(light);
        board.Draw();

        //Drawing Pawns
        for(const auto &piece : Wp_list)
        {
            if(piece != nullptr) {
                MovePieces(piece, board.DetectTile(GetMousePosition()), board);
                piece->Draw();
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Wp_list[piece->number] = nullptr;
                delete piece; continue;
            }
            }
        }
        for(const auto &piece : Bp_list)
        {
            if(piece != nullptr) {
                MovePieces(piece, board.DetectTile(GetMousePosition()), board);
                piece->Draw();
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Bp_list[piece->number] = nullptr;
                delete piece; continue;
            }
            }
        }

        //Drawing Knights
        for(const auto &piece : Wn_list)
        {
            if(piece != nullptr) {
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
            
            if (piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 };
                board.captureType = '0';
                Wn_list[piece->number] = nullptr;
                delete piece; continue;
            }
            }
        }
        for(const auto &piece : Bn_list)
        {
            if(piece != nullptr) {
                MovePieces(piece, board.DetectTile(GetMousePosition()), board);
                piece->Draw();
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Bn_list[piece->number] = nullptr;
                delete piece; continue;
            }
            }
        }

        //Drawing Rooks
        for(const auto &piece : Wr_list)
        {
            if(piece != nullptr) {
                MovePieces(piece, board.DetectTile(GetMousePosition()), board);
                piece->Draw();
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Wr_list[piece->number] = nullptr;
                delete piece; continue;
            }
            }
        }
        for(const auto &piece : Br_list)
        {
            if(piece != nullptr) {
                MovePieces(piece, board.DetectTile(GetMousePosition()), board);
                piece->Draw();
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Br_list[piece->number] = nullptr;
                delete piece; continue;
            }
            }
        }

        //Drawing Bishops
        for(const auto &piece : Wb_list)
        {
            if(piece != nullptr) {
                MovePieces(piece, board.DetectTile(GetMousePosition()), board);
                piece->Draw();
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Wb_list[piece->number] = nullptr;
                delete piece; continue;
            }
            }
        }
        for(const auto &piece : Bb_list)
        {
            if(piece != nullptr) {
                MovePieces(piece, board.DetectTile(GetMousePosition()), board);
                piece->Draw();
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Bb_list[piece->number] = nullptr;
                delete piece; continue;
            }
            }
        }

        //Drawing Kings
        if(Wking != nullptr) {
            MovePieces(Wking, board.DetectTile(GetMousePosition()), board);
            Wking->Draw();
            if(Wking->position.x == board.capture_pos.x && Wking->position.y == board.capture_pos.y && Wking->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
            }
        }
        if(Bking != nullptr) {
            MovePieces(Bking, board.DetectTile(GetMousePosition()), board);
            Bking->Draw();
            if(Bking->position.x == board.capture_pos.x && Bking->position.y == board.capture_pos.y && Bking->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
            }
        }


        //Drawing Queens
        if(Wqueen != nullptr) {
            MovePieces(Wqueen, board.DetectTile(GetMousePosition()), board);
            Wqueen->Draw();
            if(Wqueen->position.x == board.capture_pos.x && Wqueen->position.y == board.capture_pos.y && Wqueen->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Wqueen = nullptr;
                delete Wqueen;
            }
        }
        if(Bqueen != nullptr) {
            MovePieces(Bqueen, board.DetectTile(GetMousePosition()), board);
            Bqueen->Draw();
            if(Bqueen->position.x == board.capture_pos.x && Bqueen->position.y == board.capture_pos.y && Bqueen->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0';
                Bqueen = nullptr;
                delete Bqueen; 
            }
        }


        //Detect checks
        if(!board.checked) {
            state temp = board.turn;

            //Detect white checked
            board.turn = black;
            for(const auto &piece : Bb_list) {
                if(piece && piece->MoveIsValid(piece->position, Wking->position, board)) {
                    board.inCheck = true;
                    cout << "Wcheck";
                }
            }
            
            for(const auto &piece : Br_list) {
                if(piece && piece->MoveIsValid(piece->position, Wking->position, board)) {
                    board.inCheck = true;
                    cout << "Wcheck";
                }
            }
            for(const auto &piece : Bn_list) {
                if(piece && piece->MoveIsValid(piece->position, Wking->position, board)) {
                    board.inCheck = true;
                    cout << "Wcheck";
                }
            }
            if(Bqueen && Bqueen->MoveIsValid(Bqueen->position, Wking->position, board)) {
                    board.inCheck = true;
                    cout << "Wcheck";
            }

            //Detect black checked
            board.turn = white;
            for(const auto &piece : Wb_list) {
                if(piece && piece->MoveIsValid(piece->position, Bking->position, board)) {
                    board.inCheck = true;
                    cout << "Bcheck";
                }
            }
            
            for(const auto &piece : Wr_list) {
                if(piece && piece->MoveIsValid(piece->position, Bking->position, board)) {
                    board.inCheck = true;
                    cout << "Bcheck";
                }
            }
            for(const auto &piece : Wn_list) {
                if(piece && piece->MoveIsValid(piece->position, Bking->position, board)) {
                    board.inCheck = true;
                    cout << "Bcheck";
                }
            }
            if(Wqueen && Wqueen->MoveIsValid(Wqueen->position, Bking->position, board)) {
                    board.inCheck = true;
                    cout << "Bcheck";
            }
            
            board.turn = temp;
            board.checked = true;
        }
        

        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

