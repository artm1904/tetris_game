#include "game.hpp"


Game::Game() : GridInstance(), Blocks_(GetAllBlocks()), RandomGenerator_(std::random_device()()) {
    CurrentBlock_ = GetRandomBlock();
    NextBlock_ = GetRandomBlock();
}

Block Game::GetRandomBlock() {
    if (Blocks_.empty()) {
        Blocks_ = GetAllBlocks();
    }

 
    std::uniform_int_distribution<> distribution(0, Blocks_.size() - 1);
    int randomIndex = distribution(RandomGenerator_);
    Block randomBlock = Blocks_[randomIndex];
    Blocks_.erase(Blocks_.begin() + randomIndex);  // to prevent repeat the same block twice
    return randomBlock;
}

std::vector<Block> Game::GetAllBlocks() {
    return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    GridInstance.Draw();
    CurrentBlock_.Draw();
  
}