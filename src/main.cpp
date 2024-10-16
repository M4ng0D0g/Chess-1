#include <iostream>
#include "raylib.h"
#include <vector>
#include "pawn.h"
#include "knight.h"
#include "rook.h"
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

    //Load Images
    const char* WpawnImage = "./images/Chess_plt60.png"; const char* BpawnImage = "./images/Chess_pdt60.png";
    const char* WknightImage = "./images/Chess_nlt60.png"; const char* BknightImage = "./images/Chess_ndt60.png";
    const char* WrookImage = "./images/Chess_rlt60.png"; const char* BrookImage = "./images/Chess_rdt60.png";


    //Initialize Board & Piece lists
    Board board = Board(light, dark, cellSize, cellCount);
    vector<Pawn*> Wp_list(8); vector<Pawn*> Bp_list(8);
    vector<Knight*> Wn_list(2); vector<Knight*> Bn_list(2);
    vector<Rook*> Wr_list(2); vector<Rook*> Br_list(2);
    
    //Initialize Pieces' position
    Vector2 ini_pos = {0,0}; 
    
    //Initialize Pawns
    ini_pos = {0,6};
    for(llui i=0;i<Wp_list.size();i++)
    {
        ini_pos.x = float(i);
        Pawn* pawn = new Pawn(ini_pos, cellSize, WpawnImage, 'P');
        board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'P';
        Wp_list[i] = pawn;
    }
    ini_pos = {0,1};
    for(llui i=0;i<Bp_list.size();i++)
    {
        ini_pos.x = float(i);
        Pawn* pawn = new Pawn(ini_pos, cellSize, BpawnImage, 'p');
        board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'p';
        Bp_list[i] = pawn;
    }

    //Initialize Knights
    ini_pos = {1,7};
    Knight* Wknight1 = new Knight(ini_pos, cellSize, WknightImage, 'N'); Wn_list[0] = Wknight1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'N';
    ini_pos = {6,7};
    Knight* Wknight2 = new Knight(ini_pos, cellSize, WknightImage, 'N'); Wn_list[1] = Wknight2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'N';
    ini_pos = {1,0};
    Knight* Bknight1 = new Knight(ini_pos, cellSize, BknightImage, 'n'); Bn_list[0] = Bknight1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'n';
    ini_pos = {6,0};
    Knight* Bknight2 = new Knight(ini_pos, cellSize, BknightImage, 'n'); Bn_list[1] = Bknight2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'n';
    
    //Initialize Rooks
    ini_pos = {0,7};
    Rook* rook1 = new Rook(ini_pos, cellSize, WrookImage, 'R'); Wr_list[0] = rook1; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'R';
    ini_pos = {7,7};
    Rook* rook2 = new Rook(ini_pos, cellSize, WrookImage, 'R'); Wr_list[1] = rook2; board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'R';
    

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(light);
        board.Draw();

        //Detect if a valid move was made
        //and change the turn if so
        if(board.moved)
        {
            board.moved = false;
            if(board.turn == white) {board.turn = black;}
            else if(board.turn == black) {board.turn = white;}
        }

        //Drawing Pawns
        for(const auto &pawn : Wp_list)
        {
            MovePieces(pawn, board.DetectTile(GetMousePosition()), board);
            pawn->Draw();
        }
        for(const auto &pawn : Bp_list)
        {
            MovePieces(pawn, board.DetectTile(GetMousePosition()), board);
            pawn->Draw();
        }

        //Drawing Knights
        for(const auto &knight : Wn_list)
        {
            MovePieces(knight, board.DetectTile(GetMousePosition()), board);
            knight->Draw();
        }
        for(const auto &knight : Bn_list)
        {
            MovePieces(knight, board.DetectTile(GetMousePosition()), board);
            knight->Draw();
        }

        //Drawing Knights
        for(const auto &rook : Wr_list)
        {
            MovePieces(rook, board.DetectTile(GetMousePosition()), board);
            rook->Draw();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}