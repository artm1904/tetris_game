
#include "Grid/grid.hpp"
#include "raylib.h"

int main() {
    Color darkBlue = {44, 44, 128, 255};

    InitWindow(400, 800, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Grid grid{};
    grid.Print();

    while (WindowShouldClose() ==
           false) {  // Clsoe the window by pressing ECS button or clic on X button on the top-bar
        BeginDrawing();

        ClearBackground(darkBlue);

        EndDrawing();
    }

    CloseWindow();
}