#include <iostream>
#include "raylib.h"
#include <vector>
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "board.h"
#include "move.h"

using namespace std;
#define llui long long unsigned int

Color dark = {150, 107, 69, 255};
Color light = {235, 202, 174, 255};

int cellSize = 100;
int cellCount = 8;


int main()
{
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Chess");
    SetTargetFPS(60);

    //Defining images path
    const char* WpawnImage = "./images/Chess_plt60.png"; const char* BpawnImage = "./images/Chess_pdt60.png";
    const char* WknightImage = "./images/Chess_nlt60.png"; const char* BknightImage = "./images/Chess_ndt60.png";
    const char* WrookImage = "./images/Chess_rlt60.png"; const char* BrookImage = "./images/Chess_rdt60.png";
    const char* WbishopImage = "./images/Chess_blt60.png"; const char* BbishopImage = "./images/Chess_bdt60.png";

    //Initialize Board & Piece lists
    Board board = Board(light, dark, cellSize, cellCount);
    vector<Pawn*> Wp_list(8); vector<Pawn*> Bp_list(8);
    vector<Knight*> Wn_list(2); vector<Knight*> Bn_list(2);
    vector<Rook*> Wr_list(2); vector<Rook*> Br_list(2);
    vector<Bishop*> Wb_list(2); vector<Bishop*> Bb_list(2);
    
    //Initialize Pieces' position
    Vector2 ini_pos = {0,0}; 
    
    //Initialize Pawns
    ini_pos = {0,6};
    for(llui i=0;i<Wp_list.size();i++)
    {
        ini_pos.x = float(i);
        Pawn* pawn = new Pawn(ini_pos, cellSize, WpawnImage, 'P', i);
        board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'P';
        Wp_list[i] = pawn;
    }
    ini_pos = {0,1};
    for(llui i=0;i<Bp_list.size();i++)
    {
        ini_pos.x = float(i);
        Pawn* pawn = new Pawn(ini_pos, cellSize, BpawnImage, 'p', i);
        board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'p';
        Bp_list[i] = pawn;
    }

    //Initialize Knights
    ini_pos = {1,7};
    Knight* Wknight1 = new Knight(ini_pos, cellSize, WknightImage, 'N', 0); Wn_list[0] = Wknight1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'N';
    ini_pos = {6,7};
    Knight* Wknight2 = new Knight(ini_pos, cellSize, WknightImage, 'N', 1); Wn_list[1] = Wknight2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'N';
    ini_pos = {1,0};
    Knight* Bknight1 = new Knight(ini_pos, cellSize, BknightImage, 'n', 0); Bn_list[0] = Bknight1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'n';
    ini_pos = {6,0};
    Knight* Bknight2 = new Knight(ini_pos, cellSize, BknightImage, 'n', 1); Bn_list[1] = Bknight2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'n';
    
    //Initialize Rooks
    ini_pos = {0,7};
    Rook* Wrook1 = new Rook(ini_pos, cellSize, WrookImage, 'R', 0); Wr_list[0] = Wrook1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'R';
    ini_pos = {7,7};
    Rook* Wrook2 = new Rook(ini_pos, cellSize, WrookImage, 'R', 1); Wr_list[1] = Wrook2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'R';
    ini_pos = {0,0};
    Rook* Brook1 = new Rook(ini_pos, cellSize, BrookImage, 'r', 0); Br_list[0] = Brook1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'r';
    ini_pos = {7,0};
    Rook* Brook2 = new Rook(ini_pos, cellSize, BrookImage, 'r', 1); Br_list[1] = Brook2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'r';

    //Initialize Bishops
    ini_pos = {2,7};
    Bishop* Wbishop1 = new Bishop(ini_pos, cellSize, WbishopImage, 'B', 0); Wb_list[0] = Wbishop1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'B';
    ini_pos = {5,7};
    Bishop* Wbishop2 = new Bishop(ini_pos, cellSize, WbishopImage, 'B', 1); Wb_list[1] = Wbishop2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'B';
    ini_pos = {2,0};
    Bishop* Bbishop1 = new Bishop(ini_pos, cellSize, BbishopImage, 'b', 0); Bb_list[0] = Bbishop1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'b';
    ini_pos = {5,0};
    Bishop* Bbishop2 = new Bishop(ini_pos, cellSize, BbishopImage, 'b', 1); Bb_list[1] = Bbishop2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'b';

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(light);
        board.Draw();

        //Drawing Pawns
        for(const auto &piece : Wp_list)
        {
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Wp_list.erase(Wp_list.begin() + piece->number);
                delete piece; continue;
            }
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
        }
        for(const auto &piece : Bp_list)
        {
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Bp_list.erase(Bp_list.begin() + piece->number);
                delete piece; continue;
            }
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
        }

        //Drawing Knights
        for(const auto &piece : Wn_list)
        {
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
            if (piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 };
                board.captureType = '0';
                Wn_list.erase(Wn_list.begin() + piece->number);
                //delete piece; continue; I dont know why deleting pieces doesnt work on knights...
            }
        }
        for(const auto &piece : Bn_list)
        {
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Bn_list.erase(Bn_list.begin() + piece->number);
                //delete piece; continue; I dont know why deleting pieces doesnt work on knights...
            }
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
        }

        //Drawing Rooks
        for(const auto &piece : Wr_list)
        {
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Wr_list.erase(Wr_list.begin() + piece->number);
                delete piece; continue;
            }
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
        }
        for(const auto &piece : Br_list)
        {
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Br_list.erase(Br_list.begin() + piece->number);
                delete piece; continue;
            }
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
        }

        //Drawing Bishops
        for(const auto &piece : Wb_list)
        {
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Wb_list.erase(Wb_list.begin() + piece->number);
                delete piece; continue;
            }
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
        }
        for(const auto &piece : Bb_list)
        {
            if(piece->position.x == board.capture_pos.x && piece->position.y == board.capture_pos.y && piece->piece_type == board.captureType)
            {
                board.capture_pos = { -1, -1 }; 
                board.captureType = '0'; 
                Bb_list.erase(Bb_list.begin() + piece->number);
                delete piece; continue;
            }
            MovePieces(piece, board.DetectTile(GetMousePosition()), board);
            piece->Draw();
        }
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

