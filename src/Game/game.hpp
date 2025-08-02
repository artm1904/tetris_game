#pragma once
#include <random>

#include "Block/blocks.hpp"
#include "Grid/grid.hpp"

class Game {
   public:
    Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool GameOver;
    int Score;

   private:
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();
    void RotateBlock();
    bool IsBlockOutOfBounds_() const;
    void LockBlock_();
    bool IsBlockCollidingWithBlocks_() const;
    void Reset_();
    void UpdateScore_(int linesCleared, int movedDownPoints);
    Grid GridInstance;
    std::vector<Block> Blocks_;
    Block CurrentBlock_;
    Block NextBlock_;
    std::mt19937 RandomGenerator_;
};