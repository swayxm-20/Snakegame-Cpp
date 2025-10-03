#ifndef BOARD_H
#define BOARD_H

#include <utility>
#include "Snake.h"

class Board {
public:
    int width, height;
    std::pair<int,int> food;
    Board(int w = 30, int h = 20);
    void placeFood(const Snake& snake);
    void draw(const Snake& snake, int score, int level) const;
    bool isWall(int x,int y) const;
};

#endif // BOARD_H
