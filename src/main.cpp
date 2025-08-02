#include "Game/game.hpp"
#include "raylib.h"

double lastUpdateTime = 0.0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    Color darkBlue = {44, 44, 128, 255};

    InitWindow(690, 840, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Game game{};

    while (WindowShouldClose() ==
           false) {  // Clsoe the window by pressing ECS button or clic on X button on the top-bar
        BeginDrawing();

        if (EventTriggered(0.5)) {  // Update the game every 0.5 seconds

            game.MoveBlockDown();
        }

        ClearBackground(darkBlue);
        game.Draw();
        game.HandleInput();

        EndDrawing();
    }

    CloseWindow();
}