#include "colors.hpp"

cosnt Color darkGrey = {26, 31, 40, 255};
cosnt Color green = {47, 230, 23, 255};
cosnt Color red = {232, 18, 18, 255};
cosnt Color orange = {226, 116, 17, 255};
cosnt Color yellow = {237, 234, 4, 255};
cosnt Color purple = {166, 0, 247, 255};
cosnt Color cyan = {21, 204, 209, 255};
cosnt Color blue = {13, 64, 216, 255};

std::vector<Color> GetCellColors() {
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}