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
            DrawRectangle(col * CellSize_ + 1, row * CellSize_+ 1, CellSize_-1, CellSize_-1, cellColor);
        }
    }
}