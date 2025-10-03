#include "../include/Board.h"
#include "../include/Utils.h"
#include <iostream>
#include <random>

Board::Board(int w, int h) : width(w), height(h), food({-1,-1}) {}

void Board::placeFood(const Snake& snake) {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dx(0, width - 1);
    std::uniform_int_distribution<int> dy(0, height - 1);
    while (true) {
        int fx = dx(mt);
        int fy = dy(mt);
        if (!snake.occupies(fx, fy)) { food = {fx, fy}; break; }
    }
}

void Board::draw(const Snake& snake, int score, int level) const {
    clearScreen();
    // top border
    for (int i = 0; i < width + 2; ++i) std::cout << '#';
    std::cout << '\n';

    for (int y = 0; y < height; ++y) {
        std::cout << '#';
        for (int x = 0; x < width; ++x) {
            if (snake.head().first == x && snake.head().second == y) std::cout << 'O';
            else if (snake.occupies(x, y)) std::cout << 'o';
            else if (food.first == x && food.second == y) std::cout << '*';
            else std::cout << ' ';
        }
        std::cout << "#\n";
    }

    // bottom border
    for (int i = 0; i < width + 2; ++i) std::cout << '#';
    std::cout << "\n";

    std::cout << "Score: " << score << "    Level: " << level << "\n";
    std::cout << "Controls: Arrow keys or WASD. Press 'q' to quit.\n";
}

bool Board::isWall(int x, int y) const {
    return x < 0 || x >= width || y < 0 || y >= height;
}
