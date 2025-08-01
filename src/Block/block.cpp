#include "block.hpp"

Block::Block() : CellSize_(40), RotationState_(0), Colors_(GetCellColors()) {};
void Block::Draw() {
    std::vector<Position> positions = Cells[RotationState_];

    for (Position pos : positions) {
        int row = pos.Row_;
        int col = pos.Column_;
        DrawRectangle(col * CellSize_ + 1, row * CellSize_ + 1, CellSize_ - 1, CellSize_ - 1,
                      Colors_[Id]);
    }
};
