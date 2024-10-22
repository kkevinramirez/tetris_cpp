//
// Created by Kevin Ramirez on 10/18/24.
//
/*
The four ways to draw things:
DrawRectangle(int posX, int posY, int width, int height, Color color);
DrawCircle(int centerX, int centerY, float radius, Color color);
DrawLine(int startX, int startY, int endX, int endY, Color color);
DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color);

 */
#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid() {
  numRows = 20;
  numCols = 10;
  cellSize = 30;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      gridArray[row][col] = 0;
    }
  }
}

void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std ::cout << gridArray[row][col] << " ";
    }
    std::cout << std::endl;
  }

}


void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      int cellValue = gridArray[row][col];
      DrawRectangle(col * cellSize+11, row * cellSize+11 , cellSize-1, cellSize-1, colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(int row, int col) {
  if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
    return false;
  }
    return true;
}

bool Grid::IsCellEmpty(int row, int col) {
  if (gridArray[row][col] == 0) {
    return true;
  }
  return false;
}

bool Grid::IsRowFull(int row) {
  for (int col = 0; col < numCols; col++) {
    if(gridArray[row][col] == 0) {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row) {
  for (int col = 0; col < numCols; col++) {
    gridArray[row][col] = 0;
  }
}

void Grid::MoveRowDown(int row, int numRows) {
  for (int col = 0; col < numCols; col++) {
    gridArray[row + numRows][col] = gridArray[row][col];
    gridArray[row][col] = 0;

  }
}

int Grid::ClearFullRows() {
  int completed = 0;
  for (int row = numRows -1; row >= 0; row--) {
    if(IsRowFull(row)) {
      ClearRow(row);
      completed++;
    }
    else if (completed > 0) {
      MoveRowDown(row, completed);
    }
  }
  return completed;
}