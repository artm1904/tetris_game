#include "grid.hpp"

#include <iostream>

Grid::Grid() : numRows_(20), numCols_(10), cellSize_(40), colors_(GetCellColors()) {
    Initialize();
};

void Grid::Initialize() {
    for (int row = 0; row < numRows_; ++row) {
        for (int col = 0; col < numCols_; ++col) {
            grid[row][col] = 0;
        }
    }
}

void Grid::PrintGridToCmd() {
    for (int row = 0; row < numRows_; ++row) {
        for (int col = 0; col < numCols_; ++col) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<Color> Grid::GetCellColors() {
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::Draw() {
    for (int row = 0; row < numRows_; ++row) {
        for (int col = 0; col < numCols_; ++col) {
            int cellValue = grid[row][col];
            Color cellColor = colors_[cellValue];
            DrawRectangle(col * cellSize_ + 1, row * cellSize_+ 1, cellSize_-1, cellSize_-1, cellColor);
        }
    }
}