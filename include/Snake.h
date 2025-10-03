#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <utility>

enum class Direction { UP, DOWN, LEFT, RIGHT, NONE };

class Snake {
private:
    std::deque<std::pair<int,int>> body; // front() is head
    Direction dir;
    bool growFlag;
public:
    Snake(int startX = 5, int startY = 5);
    void changeDirection(Direction d);
    void move();
    void grow();
    std::pair<int,int> head() const;
    const std::deque<std::pair<int,int>>& getBody() const;
    bool collidesWithSelf() const;
    bool occupies(int x,int y) const;
};

#endif // SNAKE_H
