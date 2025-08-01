#pragma once
#include <vector>

#include "raylib.h"

class Grid {
   public:
    Grid();
    void Initialize();
    void PrintGridToCmd();
    void Draw();

    int grid[20][10];

   private:
    std::vector<Color> GetCellColors();

    int numRows_;
    int numCols_;
    int cellSize_;
    std::vector<Color> colors_{7};


};