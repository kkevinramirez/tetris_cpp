//
// Created by Kevin Ramirez on 10/19/24.
//

#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"


class Block {
  public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int col);
    std::vector<Position> GetCellPositions();
    void UndoRotation();
    int id;
    std::map<int, std::vector<Position>> cells;
    void Rotate();

  private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int colOffset;

};
