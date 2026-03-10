#include "raylib.h"
#include "chess/controller/ChessController.hpp"
#include "chess/controller/gamemode/ClassicMode.hpp"
#include "chess/model/manager/TextureManager.hpp"

int main() {
    using namespace chess::controller;
    using namespace chess::view;
    using namespace chess::utils;

    Theme& theme = Theme::CLASSIC();

    Chess game(std::make_unique<gamemode::ClassicMode>(), theme);
    Size2 windowSize = game.requiredWindowSize();

    InitWindow(windowSize.x, windowSize.y, game.title());
    SetTargetFPS(60);

    // 將工作目錄切換到執行檔所在目錄，確保相對路徑的資源能正確載入
    ChangeDirectory(GetApplicationDirectory());

    game.init();

    while (!WindowShouldClose()) {
        game.update();

        BeginDrawing();
        game.draw();
        EndDrawing();
    }

    chess::model::manager::TextureManager::instance().clearCache();
    CloseWindow();
    return 0;
}
