#pragma once
#include <map>
#include <vector>

#include "../Colors/colors.hpp"
#include "position.hpp"

class Block {
   public:
    Block();
    void Draw();
    void Move(int rowOffset, int colOffset);
    std::vector<Position> GetCellPositions();

    int Id;
    std::map<int, std::vector<Position>> Cells;

   private:
    int CellSize_;
    int RotationState_;
    std::vector<Color> Colors_;
    int RowOffset_;
    int ColOffset_;
};
