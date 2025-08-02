#pragma once
#include <vector>

#include "raylib.h"

class Grid {
   public:
    Grid();
    void Initialize();
    void PrintGridToCmd();
    void Draw();
    bool IsCellOutOfBounds(int row, int col) const;
    bool IsCellEmpty(int row, int col) const;
    int ClearFullRows();
    int GridArray[20][10];

   private:
    bool IsRowFull_(int row) const;
    void ClearRow_(int row);
    void MoveRowDown_(int row, int numRows);

    int NumRows_;
    int NumCols_;
    int CellSize_;
    std::vector<Color> Colors_{7};
};