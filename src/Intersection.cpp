#include "Intersection.h"

Intersection::Intersection(int y, int x) : x_pixel(x), y_pixel(y) {}

Intersection::~Intersection() {}

int Intersection::getX() const { return y_pixel; }

int Intersection::getY() const { return x_pixel; }

void Intersection::setUp(std::shared_ptr<Intersection> up) { this->up = up; }

std::shared_ptr<Intersection> Intersection::getUp() const { return up; }

void Intersection::setDown(std::shared_ptr<Intersection> down) { this->down = down; }

std::shared_ptr<Intersection> Intersection::getDown() const { return down; }

void Intersection::setLeft(std::shared_ptr<Intersection> left) { this->left = left; }

std::shared_ptr<Intersection> Intersection::getLeft() const { return left; }

void Intersection::setRight(std::shared_ptr<Intersection> right) { this->right = right; }

std::shared_ptr<Intersection> Intersection::getRight() const { return right; }

std::vector<std::shared_ptr<Intersection>> Intersection::getOptions() const {
    std::vector<std::shared_ptr<Intersection>> options;
    if (up != nullptr) {
        options.push_back(up);
    }
    if (down != nullptr) {
        options.push_back(down);
    }
    if (left != nullptr) {
        options.push_back(left);
    }
    if (right != nullptr) {
        options.push_back(right);
    }
    return options;
}

int Intersection::getDirection(std::shared_ptr<Intersection> dest) const {
    if (dest == up) {
        return UP;
    } else if (dest == down) {
        return DOWN;
    } else if (dest == left) {
        return LEFT;
    } else if (dest == right) {
        return RIGHT;
    } else {
        return -1;
    }
}