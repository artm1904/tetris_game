#include "block.hpp"

Block::Block()
    : CellSize_(40), RotationState_(0), Colors_(GetCellColors()), RowOffset_(0), ColOffset_(0) {};

void Block::Draw() {
    std::vector<Position> positions = GetCellPositions();

    for (const Position& pos : positions) {
        DrawRectangle(pos.Column_ * CellSize_ + 1, pos.Row_ * CellSize_ + 1, CellSize_ - 1, CellSize_ - 1,
                      Colors_[Id]);
    }
};

void Block::Move(int rowOffset, int colOffset) {
    RowOffset_ += rowOffset;
    ColOffset_ += colOffset;
}

std::vector<Position> Block::GetCellPositions() const {
    std::vector<Position> positions = Cells.at(RotationState_);
    std::vector<Position> newPositions;

    for (const Position& pos : positions) {
        newPositions.push_back(
            Position(pos.Row_ + RowOffset_, pos.Column_ + ColOffset_));
    }

    return newPositions;
}