#pragma once

#include "raylib.h"
#include <vector>
#include <memory>
#include "chess/view/Theme.hpp"
#include "chess/utils/Unit.hpp"
#include "chess/model/enums/Team.hpp"
#include "chess/model/piece/Piece.hpp"

namespace chess::model::board {
    using namespace model::enums;
    using namespace model::piece;
    using namespace view;
    using namespace utils;

    class Board {
    public:
        Theme& theme;
        Size2 cellCount;
        Size2 cellSize;

        std::vector<std::vector<SPtr<Piece>>> boardState;
        Team turn = Team::White;

    public:
        Board(
            const Size2& count,
            const Size2& size,
            Theme& t
        ) : theme(t), cellCount(count), cellSize(size) {
            boardState = std::vector<std::vector<SPtr<Piece>>>(
                cellCount.y, std::vector<SPtr<Piece>>(
                    cellCount.x, nullptr
                )
            );
        }
        
        //Draw a grid with cellCount * cellCount, with each tile
        //is the size of cellSize * cellSize
        void draw() {
            for (int r = 0; r < (int)cellCount.x; ++r) {
                for (int c = 0; c < (int)cellCount.y; ++c) {
                    Color color = ((r + c) & 1)  ? theme.getDarkColor() : theme.getLightColor();
                    DrawRectangle(r * cellSize.x, c * cellSize.y, cellSize.x, cellSize.y, color);
                }
            }
        }
        
        Loc2<int> detectTile(Vector2 mouse) {
            Loc2<int> tile{0,0}; 
            for (int i = 0; i < (int)cellCount.x; ++i) {
                if (mouse.x >= i * (int)cellSize.x && mouse.x <= (i+1) * (int)cellSize.x) tile.x = i;
            }
            for(int i = 0; i < (int)cellCount.y; ++i) {
                if (mouse.y >= i * (int)cellSize.y && mouse.y <= (i+1) * (int)cellSize.y) tile.y = i;
            }
            return tile;
        }

    };


}
