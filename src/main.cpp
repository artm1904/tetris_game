#include "Game/Colors/colors.hpp"
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
    InitWindow(690, 840, "Simple Tetris Game");
    SetTargetFPS(60);

    Font defaultFont = LoadFontEx("../fonts/monogram.ttf", 64, 0, 0);

    Game game{};

    // Clsoe the window by pressing ECS button or clic on X button on the top-bar
    while (WindowShouldClose() == false) {
        UpdateMusicStream(game.Music);
        game.HandleInput();

        if (EventTriggered(0.5)) {  // Update the game every 0.5 seconds

            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        //----Drawing UI elements----
        DrawTextEx(defaultFont, "Score:", {490, 35}, 45, 5, WHITE);
        DrawTextEx(defaultFont, "Next:", {490, 275}, 45, 5, WHITE);
        DrawRectangleRounded({450, 80, 210, 60}, 0.5f, 0, lightBlue);
        DrawRectangleRounded({450, 320, 210, 160}, 0.2f, 0, lightBlue);
        char scoreText[20];
        snprintf(scoreText, sizeof(scoreText), "%d", game.Score);
        Vector2 scoreSize = MeasureTextEx(defaultFont, scoreText, 38, 2);
        DrawTextEx(defaultFont, scoreText, {470 + (125 - scoreSize.x) / 2, 90}, 38, 2, BLACK);

        if (game.GameOver) {
            //----Draw Game Over screen----
            DrawTextEx(defaultFont, "GAME", {490, 620}, 45, 5, WHITE);
            DrawTextEx(defaultFont, "OVER!", {490, 665}, 45, 5, WHITE);
            DrawTextEx(defaultFont, "Press R to restart", {50, 350}, 30, 2, RED);
        } else {
            //----Draw the game elements----
            game.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
}