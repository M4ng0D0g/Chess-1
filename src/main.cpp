#include <iostream>
#include "raylib.h"
#include <vector>
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
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
    const char* WkingImage = "./images/Chess_klt60.png"; const char* BkingImage = "./images/Chess_kdt60.png";
    const char* WqueenImage = "./images/Chess_qlt60.png"; const char* BqueenImage = "./images/Chess_qdt60.png";

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
        Pawn* pawn = new Pawn(ini_pos, cellSize, WpawnImage, 'P', int(i));
        board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'P';
        Wp_list[i] = pawn;
    }
    ini_pos = {0,1};
    for(llui i=0;i<Bp_list.size();i++)
    {
        ini_pos.x = float(i);
        Pawn* pawn = new Pawn(ini_pos, cellSize, BpawnImage, 'p', int(i));
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


    //Initialize Kings
    ini_pos = {4,7};
    King* Wking = new King(ini_pos, cellSize, WkingImage, 'K', 0); board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'K';
    ini_pos = {4,0};
    King* Bking = new King(ini_pos, cellSize, BkingImage, 'k', 0); board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'k';


    //Initialize Queens
    ini_pos = {3,7};
    Queen* Wqueen = new Queen(ini_pos, cellSize, WqueenImage, 'Q', 0); board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'Q';
    ini_pos = {3,0};
    Queen* Bqueen = new Queen(ini_pos, cellSize, BqueenImage, 'q', 0); board.board_state[int(ini_pos.y)][int(ini_pos.x)] = 'q';

    while (WindowShouldClose() == false)
    {
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

