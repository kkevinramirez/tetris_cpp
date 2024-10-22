//
// Created by Kevin Ramirez on 10/20/24.
//

#pragma once
#include "grid.h"
#include "blocks.cpp"



class Game {
  public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    Grid grid;
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    bool gameOver;
    int score;



  private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool BlockFits();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    void Reset();
    void updateScore(int LinesCleared, int moveDownPoints);

};
