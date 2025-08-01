#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialize the window and OpenGL context
    InitWindow(screenWidth, screenHeight, "tetris_game - raylib");

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You are linked with Raylib!", 160, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}