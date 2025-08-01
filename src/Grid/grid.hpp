#pragma once
#include <vector>

#include "raylib.h"

class Grid {
   public:
    Grid();
    void Initialize();
    void PrintGridToCmd();
    void Draw();

    int GridArray[20][10];

   private:
   

    int NumRows_;
    int NumCols_;
    int CellSize_;
    std::vector<Color> Colors_{7};


};