#pragma once
#include "Block/blocks.hpp"
#include "Grid/grid.hpp"
#include <random>

class Game {
   public:
    Game();

    Block GetRandomBlock();

    std::vector<Block> GetAllBlocks();

    void Draw();

    Grid GridInstance;

   private:
    std::vector<Block> Blocks_;
    Block CurrentBlock_;
    Block NextBlock_;
    std::mt19937 RandomGenerator_;
};