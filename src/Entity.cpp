#include "Entity.h"

Entity::Entity(float x, float y, int direction) : x(x), y(y), direction(direction) { sprites = {}; }

void Entity::setDirection(int d) { direction = d; }

float Entity::getX() const { return x; }

float Entity::getY() const { return y; }

bool Entity::isAtIntersection(std::shared_ptr<Intersection> dest) {
    if (dest == nullptr) {
        return false;
    }
    switch (direction) {
    case UP:
        return (y - dest->getY()) <= 1;
    case DOWN:
        return (dest->getY() - y) <= 1;
    case LEFT:
        return (x - dest->getX()) <= 1;
    case RIGHT:
        return (dest->getX() - x) <= 1;
    case STOP:
        return true;
    default:
        return false;
    }
}