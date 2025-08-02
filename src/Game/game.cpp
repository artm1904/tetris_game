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

void Game::HandleInput() {
    if (IsKeyPressed(KEY_LEFT)) {
        MoveBlockLeft();
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        MoveBlockRight();
    }
    if (IsKeyPressed(KEY_DOWN)) {
        MoveBlockDown();
    }
    if (IsKeyPressed(KEY_UP)) {
        RotateBlock();
    }
}

void Game::MoveBlockLeft() {
    CurrentBlock_.Move(0, -1);
    if (IsBlockOutOfBounds_()) {
        CurrentBlock_.Move(0, 1);  // revert the move if out of bounds
    }
}

void Game::MoveBlockRight() {
    CurrentBlock_.Move(0, 1);
    if (IsBlockOutOfBounds_()) {
        CurrentBlock_.Move(0, -1);  // revert the move if out of bounds
    }
}

void Game::MoveBlockDown() {
    CurrentBlock_.Move(1, 0);
    if (IsBlockOutOfBounds_()) {
        CurrentBlock_.Move(-1, 0);  // revert the move if out of bounds
    }
}

void Game::RotateBlock() {
    auto previousRotationState = CurrentBlock_.GetRotationState();
    CurrentBlock_.SetRotationState((CurrentBlock_.GetRotationState() + 1) % 4);
    if (IsBlockOutOfBounds_()) {
        CurrentBlock_.SetRotationState(
            previousRotationState);  // revert the rotation if out of bounds
    }
}

bool Game::IsBlockOutOfBounds_() const {
    std::vector<Position> positions = CurrentBlock_.GetCellPositions();
    for (const Position& pos : positions) {
        if (GridInstance.IsCellOutOfBounds(pos.Row_, pos.Column_)) {
            return true;
        }
    }
    return false;
}
