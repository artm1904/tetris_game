#include "blocks.hpp"

LBlock::LBlock() {
    Id = 1;
    Cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
    Cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
    Cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
    Cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
}

JBlock::JBlock() {
    Id = 2;
    Cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
    Cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
    Cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
    Cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
}

IBlock::IBlock() {
    Id = 3;
    Cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
    Cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
    Cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
    Cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
}

OBlock::OBlock() {
    Id = 4;
    Cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
}

SBlock::SBlock() {
    Id = 5;
    Cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
    Cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
    Cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
    Cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
}

TBlock::TBlock() {
    Id = 6;
    Cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
    Cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
    Cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
    Cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
}

ZBlock::ZBlock() {
    Id = 7;
    Cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    Cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
    Cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    Cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
}
