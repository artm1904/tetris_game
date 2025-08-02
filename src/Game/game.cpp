#include "game.hpp"

Game::Game()
    : GameOver(false),
      Score(0),
      GridInstance_(),
      Blocks_(GetAllBlocks_()),
      RandomGenerator_(std::random_device()()) {
    CurrentBlock_ = GetRandomBlock_();
    NextBlock_ = GetRandomBlock_();
    InitAudioDevice();  // Initialize audio device for sound effects if needed
    Music = LoadMusicStream("../../sounds/music.mp3");
    PlayMusicStream(Music);
    RotareSound_ = LoadSound("../../sounds/rotate.mp3");
    ClearSound_ = LoadSound("../../sounds/clear.mp3");
}

Game::~Game() {
    CloseAudioDevice();  // Close audio device if it was initialized
    UnloadMusicStream(Music);
    UnloadSound(RotareSound_);
    UnloadSound(ClearSound_);
}

Block Game::GetRandomBlock_() {
    if (Blocks_.empty()) {
        Blocks_ = GetAllBlocks_();
    }

    std::uniform_int_distribution<> distribution(0, Blocks_.size() - 1);
    int randomIndex = distribution(RandomGenerator_);
    Block randomBlock = Blocks_[randomIndex];
    Blocks_.erase(Blocks_.begin() + randomIndex);  // to prevent repeat the same block twice
    return randomBlock;
}

std::vector<Block> Game::GetAllBlocks_() {
    return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    GridInstance_.Draw();
    CurrentBlock_.Draw(21, 21);

    switch (NextBlock_.Id)  // Draw the next block in a fixed position
    {
        case 4:  // OBlock
            NextBlock_.Draw(355, 360);
            break;
        case 3:  // IBlock
            NextBlock_.Draw(355, 380);
            break;
        default:
            NextBlock_.Draw(380, 360);
            break;
    }
}

void Game::HandleInput() {
    if (GameOver) {
        if (IsKeyPressed(KEY_R)) {
            Reset_();
        }

        return;
    }

    if (IsKeyPressed(KEY_LEFT)) {
        MoveBlockLeft_();
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        MoveBlockRight_();
    }
    if (IsKeyPressed(KEY_DOWN)) {
        MoveBlockDown();
        UpdateScore_(0, 1);
    }
    if (IsKeyPressed(KEY_UP)) {
        RotateBlock_();
    }
}

void Game::MoveBlockLeft_() {
    if (!GameOver) {
        CurrentBlock_.Move(0, -1);
        if (IsBlockOutOfBounds_() || IsBlockCollidingWithBlocks_()) {
            CurrentBlock_.Move(0, 1);  // revert the move if out of bounds
        }
    }
}

void Game::MoveBlockRight_() {
    if (!GameOver) {
        CurrentBlock_.Move(0, 1);
        if (IsBlockOutOfBounds_() || IsBlockCollidingWithBlocks_()) {
            CurrentBlock_.Move(0, -1);  // revert the move if out of bounds
        }
    }
}

void Game::MoveBlockDown() {
    if (!GameOver) {
        CurrentBlock_.Move(1, 0);
        if (IsBlockOutOfBounds_() || IsBlockCollidingWithBlocks_()) {
            CurrentBlock_.Move(-1, 0);  // revert the move if out of bounds
            LockBlock_();
        }
    }
}

void Game::RotateBlock_() {
    auto previousRotationState = CurrentBlock_.GetRotationState();
    if (CurrentBlock_.Id == 4) {
        // OBlock does not rotate, so we skip the rotation logic

    } else {
        // For other blocks, we perform the rotation
        CurrentBlock_.SetRotationState((CurrentBlock_.GetRotationState() + 1) % 4);
        PlaySound(RotareSound_);
    }

    if (IsBlockOutOfBounds_() || IsBlockCollidingWithBlocks_()) {
        CurrentBlock_.SetRotationState(
            previousRotationState);  // revert the rotation if out of bounds
    }
}

bool Game::IsBlockOutOfBounds_() const {
    std::vector<Position> positions = CurrentBlock_.GetCellPositions();
    for (const Position& pos : positions) {
        if (GridInstance_.IsCellOutOfBounds(pos.Row_, pos.Column_)) {
            return true;
        }
    }
    return false;
}

void Game::LockBlock_() {
    std::vector<Position> positions = CurrentBlock_.GetCellPositions();
    for (const Position& pos : positions) {
        GridInstance_.GridArray[pos.Row_][pos.Column_] = CurrentBlock_.Id;
    }

    // Reset the current block and generate a new one
    CurrentBlock_ = NextBlock_;
    if (IsBlockCollidingWithBlocks_() == true) {
        // If the new block collides, it means the game is over
        GameOver = true;
        return;
    }

    NextBlock_ = GetRandomBlock_();

    auto linesCleared = GridInstance_.ClearFullRows();  // Clear full rows after locking the block
    if (linesCleared > 0) {
        PlaySound(ClearSound_);
        UpdateScore_(linesCleared, 0);
    }
}

bool Game::IsBlockCollidingWithBlocks_() const {
    std::vector<Position> positions = CurrentBlock_.GetCellPositions();
    for (const Position& pos : positions) {
        if (GridInstance_.IsCellEmpty(pos.Row_, pos.Column_) == false) {
            return true;  // If any cell is not empty, it means collision
        }
    }
    return false;
}

void Game::Reset_() {
    GameOver = false;
    Score = 0;
    GridInstance_.Initialize();
    Blocks_ = GetAllBlocks_();
    CurrentBlock_ = GetRandomBlock_();
    NextBlock_ = GetRandomBlock_();
}

void Game::UpdateScore_(int linesCleared, int movedDownPoints) {
    switch (linesCleared) {
        case 1:
            Score += 100;
            break;
        case 2:
            Score += 300;
            break;
        case 3:
            Score += 500;
            break;
        case 4:
            Score += 800;
            break;
        default:
            break;
    }
    Score += movedDownPoints;
}
