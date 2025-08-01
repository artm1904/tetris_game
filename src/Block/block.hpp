#pragma once
#include <map>
#include <vector>

#include "position.hpp"

class Block {
   public:
    Block();

    int Id;
    std::map<int, std::vector<Position>> Cells;

   private:
    int CellSize_;
    int RotationState_;
    
};