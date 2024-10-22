//
// Created by Kevin Ramirez on 10/18/24.
//

#pragma once
#include <vector>
#include "raylib.h"



class Grid {
  public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
    int ClearFullRows();
    int gridArray[20][10];


  private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRow);
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};

