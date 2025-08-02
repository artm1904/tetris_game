#include "block.hpp"

Block::Block()
    : CellSize_(40), RotationState_(0), Colors_(GetCellColors()), RowOffset_(0), ColOffset_(0) {};

void Block::Draw() {
    std::vector<Position> positions = GetCellPositions();

    for (Position pos : positions) {
        int row = pos.Row_;
        int col = pos.Column_;
        DrawRectangle(col * CellSize_ + 1, row * CellSize_ + 1, CellSize_ - 1, CellSize_ - 1,
                      Colors_[Id]);
    }
};

void Block::Move(int rowOffset, int colOffset) {
    RowOffset_ += rowOffset;
    ColOffset_ += colOffset;
}

std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> positions = Cells[RotationState_];
    std::vector<Position> newPositions;

    for (Position pos : positions) {
        int row = pos.Row_ + RowOffset_;
        int col = pos.Column_ + ColOffset_;
        newPositions.push_back(Position(row, col));
    }

    return newPositions;
}