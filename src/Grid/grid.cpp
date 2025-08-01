#include "grid.hpp"

#include <iostream>

Grid::Grid() : numRows_(20), numCols_(10), cellSize_(30) { Initialize(); };

void Grid::Initialize() {
    for (int row = 0; row < numRows_; ++row) {
        for (int col = 0; col < numCols_; ++col) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < numRows_; ++row) {
        for (int col = 0; col < numCols_; ++col) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}
