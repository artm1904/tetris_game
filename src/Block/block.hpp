#pragma once
#include <map>
#include <vector>
#include "../Colors/colors.hpp"

#include "position.hpp"

class Block {
   public:
    Block();
    
    void Draw();

    int Id;
    std::map<int, std::vector<Position>> Cells;

   private:
    int CellSize_;
    int RotationState_;
    std::vector<Color> Colors_;



};


