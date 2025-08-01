
#include "Grid/grid.hpp"
#include "Block/blocks.hpp"
#include "raylib.h"

int main() {
    Color darkBlue = {44, 44, 128, 255};

    InitWindow(400, 800, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Grid grid{};
    grid.PrintGridToCmd();
    LBlock block{};
    
    
    while (WindowShouldClose() ==
    false) {  // Clsoe the window by pressing ECS button or clic on X button on the top-bar
        BeginDrawing();
        
        ClearBackground(darkBlue);
        grid.Draw();
        
        block.Draw();

        EndDrawing();
    }

    CloseWindow();
}