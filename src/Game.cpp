#include "../include/Game.h"
#include "../include/Utils.h"
#include <thread>
#include <iostream>
#include <algorithm>

#ifdef _WIN32
    #include <conio.h>
#endif

Game::Game(int w, int h)
    : board(w,h), snake(w/2, h/2), nextDir(Direction::NONE),
      running(false), score(0), level(1), speedMs(140)
{
    board.placeFood(snake);
}

void Game::run() {
    initTerminal();
    running = true;
    std::thread inputThread(&Game::inputLoop, this);

    while (running) {
        // apply pending direction
        Direction d = nextDir.load();
        if (d != Direction::NONE) { snake.changeDirection(d); nextDir.store(Direction::NONE); }

        snake.move();

        auto head = snake.head();
        if (board.isWall(head.first, head.second) || snake.collidesWithSelf()) {
            running = false; break;
        }

        if (head == board.food) {
            snake.grow();
            score += 10;
            if (score % 50 == 0) { level++; speedMs = std::max(40, speedMs - 10); }
            board.placeFood(snake);
        }

        board.draw(snake, score, level);
        sleepMs(speedMs);
    }

    // game over
    clearScreen();
    std::cout << "Game Over! Final Score: " << score << "\n";
    std::cout << "Press any key to exit...\n";
    // wait for key
    while (!kbhit()) sleepMs(50);
    getch();

    running = false;
    if (inputThread.joinable()) inputThread.join();
}

void Game::inputLoop() {
    while (running) {
        if (!kbhit()) { sleepMs(10); continue; }

        int c = getch();

    #ifdef _WIN32
        if (c == 0 || c == 224) {
            int e = getch();
            switch (e) {
                case 72: nextDir.store(Direction::UP); break;
                case 80: nextDir.store(Direction::DOWN); break;
                case 75: nextDir.store(Direction::LEFT); break;
                case 77: nextDir.store(Direction::RIGHT); break;
            }
            continue;
        }
    #else
        if (c == 27) {
            // possible arrow sequence on POSIX: 27, 91, {A,B,C,D}
            if (kbhit()) {
                int c2 = getch();
                if (c2 == '[' && kbhit()) {
                    int c3 = getch();
                    switch (c3) {
                        case 'A': nextDir.store(Direction::UP); break;
                        case 'B': nextDir.store(Direction::DOWN); break;
                        case 'D': nextDir.store(Direction::LEFT); break;
                        case 'C': nextDir.store(Direction::RIGHT); break;
                    }
                    continue;
                }
            }
        }
    #endif

        // WASD or single chars
        char ch = static_cast<char>(c);
        if (ch == 'w' || ch == 'W') nextDir.store(Direction::UP);
        else if (ch == 's' || ch == 'S') nextDir.store(Direction::DOWN);
        else if (ch == 'a' || ch == 'A') nextDir.store(Direction::LEFT);
        else if (ch == 'd' || ch == 'D') nextDir.store(Direction::RIGHT);
        else if (ch == 'q' || ch == 'Q') { running = false; break; }

        sleepMs(10);
    }
}
