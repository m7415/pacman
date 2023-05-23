#include "Pacman.h"

Pacman::Pacman(float x, float y, int direction, std::shared_ptr<Intersection> destination)
    : Entity(x, y, direction) {
    sprites = {
        {489, 1, 13, 13}, {473, 1, 13, 13},  {457, 1, 13, 13},  // RIGHT
        {489, 1, 13, 13}, {473, 17, 13, 13}, {457, 17, 13, 13}, // LEFT
        {489, 1, 13, 13}, {473, 33, 13, 13}, {457, 33, 13, 13}, // UP
        {489, 1, 13, 13}, {473, 49, 13, 13}, {457, 49, 13, 13}  // DOWN
    };
    speed = 3.0f;
    dest = destination;
}

Pacman::~Pacman() {}

int Pacman::getX() const { return x; }

int Pacman::getY() const { return y; }

void Pacman::setEating(bool e) { isEating = e; }

bool Pacman::getEating() const { return isEating; }

void Pacman::setPlayerDirection(int d) {
    playerDirection = d;
    switch (d) {
    case UP:
        if (direction == DOWN) {
            direction = d;
            dest = dest->getUp();
        }
        break;
    case DOWN:
        if (direction == UP) {
            direction = d;
            dest = dest->getDown();
        }
        break;
    case LEFT:
        if (direction == RIGHT) {
            direction = d;
            dest = dest->getLeft();
        }
        break;
    case RIGHT:
        if (direction == LEFT) {
            direction = d;
            dest = dest->getRight();
        }
        break;
    default:
        break;
    }
}

std::shared_ptr<Intersection> Pacman::makeTurn() {
    if (dest != nullptr) {
        x = dest->getX();
        y = dest->getY();
        switch (playerDirection) {
        case UP:
            direction = UP;
            return dest->getUp();
            break;
        case DOWN:
            direction = DOWN;
            return dest->getDown();
            break;
        case LEFT:
            direction = LEFT;
            return dest->getLeft();
            break;
        case RIGHT:
            direction = RIGHT;
            return dest->getRight();
            break;
        default:
            break;
        }
    }
    return nullptr;
}

void Pacman::move() {
    switch (direction) {
    case UP:
        y -= speed;
        break;
    case DOWN:
        y += speed;
        break;
    case LEFT:
        x -= speed;
        if (x < 0) {
            x = 448;
        }
        break;
    case RIGHT:
        x += speed;
        if (x > 448) {
            x = 0;
        }
        break;
    case STOP:
        break;
    default:
        break;
    }
    if (isAtIntersection(dest)) {
        std::shared_ptr<Intersection> temp = makeTurn();
        if (temp == nullptr) {
            direction = STOP;
        } else {
            dest = temp;
        }
    }
}

SDL_Rect Pacman::getSprite(int frame, int direction) {
    if (direction == STOP) {
        return lastSprite;
    } else {
        lastSprite = sprites[3 * direction + (frame / 2) % 3];
        return sprites[3 * direction + (frame / 2) % 3];
    }
}

void Pacman::render(int frame, SDL_Renderer *renderer, SDL_Texture *texture) {
    SDL_Rect src = getSprite(frame, direction);
    int x_int = (int)x;
    int y_int = (int)y;
    int width = 2 * src.w;
    int height = 2 * src.h;
    SDL_Rect dst = {x_int - width / 2, y_int - height / 2, width, height};
    SDL_RenderCopy(renderer, texture, &src, &dst);
}