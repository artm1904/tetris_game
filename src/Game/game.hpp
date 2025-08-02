#pragma once
#include <random>

#include "Block/blocks.hpp"
#include "Grid/grid.hpp"

class Game {
   public:
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool GameOver;
    int Score;
    Music Music;
    Grid GridInstance_;

   private:
    Block GetRandomBlock_();
    std::vector<Block> GetAllBlocks_();
    void MoveBlockLeft_();
    void MoveBlockRight_();
    void RotateBlock_();
    bool IsBlockOutOfBounds_() const;
    void LockBlock_();
    bool IsBlockCollidingWithBlocks_() const;
    void Reset_();
    void UpdateScore_(int linesCleared, int movedDownPoints);

    std::vector<Block> Blocks_;
    Block CurrentBlock_;
    Block NextBlock_;
    std::mt19937 RandomGenerator_;
    Sound RotareSound_;
    Sound ClearSound_;
};