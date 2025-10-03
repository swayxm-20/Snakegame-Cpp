#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Snake.h"
#include <atomic>

class Game {
private:
    Board board;
    Snake snake;
    std::atomic<Direction> nextDir;
    std::atomic<bool> running;
    int score;
    int level;
    int speedMs; // milliseconds per frame
public:
    Game(int w=30,int h=20);
    void run();
    void inputLoop();
};

#endif // GAME_H
