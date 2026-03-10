#pragma once

#include "raylib.h"
#include <vector>
#include "chess/view/Theme.hpp"
#include "chess/utils/Unit.hpp"

namespace chess::model::board {
    using namespace view;
    using namespace utils;

    enum state {
        white, black
    };

    class Board {
    private:
        Theme& _theme;
        Size2 _cellCount;
        Size2 _cellSize;

    public:
        vector<vector<char>> board_state;
        state turn = white;
        bool moved = false;
        bool inCheck = false;
        bool checked = false;
        Vector2 capture_pos = {-1, -1};
        char captureType = '0';

        //Draw a grid with cellCount * cellCount, with each tile
        //is the size of cellSize * cellSize
        Board(
            const Size2& cellCount,
            const Size2& cellSize,
            Theme& theme
        ) : _cellCount(cellCount), _cellSize(cellSize), _theme(theme) {
            vector<char> v(cellCount, '0');
            vector<vector<char>> vec(cellCount, v);
            board_state = vec;
        }
        
        //Draw
        void draw() {
            for (int r = 0; r < _cellCount.x; ++r) {
                for (int c = 0; c < _cellCount.y; ++c) {
                    Color color = ((r + c) & 1)  ? _theme.getDarkColor() : _theme.getLightColor();
                    DrawRectangle(r * _cellSize.x, c * _cellSize.y, _cellSize.x, _cellSize.y, color);
                }
            }
        }
        
        //Detect which tile the mouse is in, with (0,0) being the top left
        //tile, and increase in x going right, increase in y going down
        Loc2<int> detectTile(Vector2 mouse) {
            Loc2<int> tile{0,0}; 
            for (int i = 0; i < _cellCount.x; ++i) {
                if (mouse.x >= i * _cellSize.x && mouse.x <= (i+1) * _cellSize.x) tile.x = i;
            }
            for(int i = 0; i < _cellCount.y; ++i) {
                if (mouse.y >= i * _cellSize.y && mouse.y <= (i+1) * _cellSize.y) tile.y = i;
            }
            return tile;
        }

    };


}
