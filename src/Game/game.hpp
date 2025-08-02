#pragma once
#include <random>

#include "Block/blocks.hpp"
#include "Grid/grid.hpp"

class Game {
   public:
    Game();

    Block GetRandomBlock();

    std::vector<Block> GetAllBlocks();

    void Draw();

    void HandleInput();

    void MoveBlockLeft();

    void MoveBlockRight();

    void MoveBlockDown();

    void RotateBlock();

    Grid GridInstance;

   private:
    bool IsBlockOutOfBounds_() const;
    std::vector<Block> Blocks_;
    Block CurrentBlock_;
    Block NextBlock_;
    std::mt19937 RandomGenerator_;
};