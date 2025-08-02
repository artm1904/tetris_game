#include "Game/game.hpp"
#include "raylib.h"

int main() {
    Color darkBlue = {44, 44, 128, 255};

    InitWindow(400, 800, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Game game{};

    while (WindowShouldClose() ==
           false) {  // Clsoe the window by pressing ECS button or clic on X button on the top-bar
        BeginDrawing();

        ClearBackground(darkBlue);
        game.Draw();
        game.HundleInput();

        EndDrawing();
    }

    CloseWindow();
}