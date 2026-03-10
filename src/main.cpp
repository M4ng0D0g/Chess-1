#include "raylib.h"
#include "chess/controller/ChessController.hpp"
#include "chess/controller/gamemode/ClassicMode.hpp"

int main() {
    using namespace chess::controller;
    using namespace chess::view;
    using namespace chess::utils;

    Theme& theme = Theme::CLASSIC();

    Chess game(std::make_unique<gamemode::ClassicMode>(), theme);
    Size2 windowSize = game.requiredWindowSize();

    InitWindow(windowSize.x, windowSize.y, game.title());
    SetTargetFPS(60);

    game.init();

    while (!WindowShouldClose()) {
        game.update();

        BeginDrawing();
        game.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
