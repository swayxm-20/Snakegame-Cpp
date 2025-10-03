#include "../include/Snake.h"

Snake::Snake(int startX, int startY) : dir(Direction::RIGHT), growFlag(false) {
    body.emplace_back(startX, startY);
    // start length 3
    body.emplace_back(startX - 1, startY);
    body.emplace_back(startX - 2, startY);
}

void Snake::changeDirection(Direction d) {
    // prevent immediate reversal
    if ((dir == Direction::UP && d == Direction::DOWN) ||
        (dir == Direction::DOWN && d == Direction::UP) ||
        (dir == Direction::LEFT && d == Direction::RIGHT) ||
        (dir == Direction::RIGHT && d == Direction::LEFT)) {
        return;
    }
    if (d != Direction::NONE) dir = d;
}

void Snake::move() {
    auto [hx, hy] = body.front();
    int nx = hx, ny = hy;
    switch (dir) {
        case Direction::UP: ny = hy - 1; break;
        case Direction::DOWN: ny = hy + 1; break;
        case Direction::LEFT: nx = hx - 1; break;
        case Direction::RIGHT: nx = hx + 1; break;
        default: break;
    }
    body.emplace_front(nx, ny);
    if (!growFlag) body.pop_back();
    else growFlag = false;
}

void Snake::grow() { growFlag = true; }

std::pair<int,int> Snake::head() const { return body.front(); }

const std::deque<std::pair<int,int>>& Snake::getBody() const { return body; }

bool Snake::collidesWithSelf() const {
    auto h = head();
    int i = 0;
    for (const auto &p : body) {
        if (i++ == 0) continue; // skip head
        if (p == h) return true;
    }
    return false;
}

bool Snake::occupies(int x, int y) const {
    for (const auto &p : body) if (p.first == x && p.second == y) return true;
    return false;
}
