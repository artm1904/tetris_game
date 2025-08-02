#include "grid.hpp"

#include <iostream>

#include "../Colors/colors.hpp"

Grid::Grid() : NumRows_(20), NumCols_(10), CellSize_(40), Colors_(GetCellColors()) {
    Initialize();
};

void Grid::Initialize() {
    for (int row = 0; row < NumRows_; ++row) {
        for (int col = 0; col < NumCols_; ++col) {
            GridArray[row][col] = 0;
        }
    }
}

void Grid::PrintGridToCmd() {
    for (int row = 0; row < NumRows_; ++row) {
        for (int col = 0; col < NumCols_; ++col) {
            std::cout << GridArray[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    for (int row = 0; row < NumRows_; ++row) {
        for (int col = 0; col < NumCols_; ++col) {
            int cellValue = GridArray[row][col];
            Color cellColor = Colors_[cellValue];
            DrawRectangle(col * CellSize_ + 1, row * CellSize_ + 1, CellSize_ - 1, CellSize_ - 1,
                          cellColor);
        }
    }
}

bool Grid::IsCellOutOfBounds(int row, int col) const {
    return (row < 0 || row >= NumRows_ || col < 0 || col >= NumCols_);
}

bool Grid::IsCellEmpty(int row, int col) const {
    return GridArray[row][col] == 0;  // Assuming 0 means empty cell
}

int Grid::ClearFullRows() {
    int clearedRows = 0;
    for (int row = NumRows_ - 1; row >= 0; --row) {
        if (IsRowFull_(row)) {
            ClearRow_(row);
            clearedRows++;

        } else if (clearedRows > 0) {
            MoveRowDown_(row, clearedRows);
        }
    }
    return clearedRows;
}

bool Grid::IsRowFull_(int row) const {
    for (int col = 0; col < NumCols_; ++col) {
        if (GridArray[row][col] == 0) {
            return false;  // If any cell in the row is empty, the row is not full
        }
    }
    return true;
}

void Grid::ClearRow_(int row) {
    for (int col = 0; col < NumCols_; ++col) {
        GridArray[row][col] = 0;  // Clear the row by setting all cells to 0
    }
}

void Grid::MoveRowDown_(int row, int numRows) {
    for (int col = 0; col < NumCols_; ++col) {
        GridArray[row + numRows][col] = GridArray[row][col];  // Move the row down
        GridArray[row][col] = 0;                              // Clear the original row
    }
}
