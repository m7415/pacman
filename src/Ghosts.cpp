#include "Ghosts.h"

Ghosts::Ghosts(float x, float y, int direction, Tile target, int dotCounter)
    : Entity(x, y, direction), scatterTarget(target), dotCounter(dotCounter) {
    speed = 0.0f;
    rng.seed(std::random_device()());
}

Ghosts::~Ghosts() {}

void Ghosts::setMode(int mode) {
    if (mode == FRIGHTENED) {
        modeTimer = SDL_GetTicks();
    }
    if (this->mode == EYES) {
        previousMode = mode;
        return;
    }
    previousMode = this->mode;
    this->mode = mode;
}

int Ghosts::getMode() { return mode; }

SDL_Rect Ghosts::getSprite(int frame, int direction) {
    if (mode == FRIGHTENED) {
        return sprites[8 + (frame / 2) % 4];
    } else if (mode == EYES) {
        return sprites[12 + direction];
    } else {
        return sprites[2 * direction + (frame / 2) % 2];
    }
}

void Ghosts::render(int frame, SDL_Renderer *renderer, SDL_Texture *texture) {
    SDL_Rect src = getSprite(frame, direction);
    int x_int = (int)x;
    int y_int = (int)y;
    int width = 2 * src.w;
    int height = 2 * src.h;
    SDL_Rect dst = {x_int - width / 2, y_int - height / 2, width, height};
    SDL_RenderCopy(renderer, texture, &src, &dst);
}

void Ghosts::move(int pacmanX, int pacmanY, std::shared_ptr<Intersection> dest, int dotEaten) {
    if (dotEaten >= dotCounter && !isFree) {
        speed = 1.0f;
        x = getOrig().x * CELL_SIZE;
        y = getOrig().y * CELL_SIZE + CELL_SIZE / 2;
        isFree = true;
    }

    if (mode == FRIGHTENED) {
        if (SDL_GetTicks() - modeTimer > 7000) {
            mode = previousMode;
        }
    }
    if (mode == EYES) {
        int col = x / CELL_SIZE;
        int row = y / CELL_SIZE;
        if (getOrig().x == col && getOrig().y == row) {
            mode = previousMode;
        }
    }
    switch (direction) {
    case UP:
        y -= speed;
        break;
    case DOWN:
        y += speed;
        break;
    case LEFT:
        x -= speed;
        break;
    case RIGHT:
        x += speed;
        break;
    case STOP:
        break;
    default:
        break;
    }
    if (isAtIntersection(dest)) {
        std::shared_ptr<Intersection> temp = makeTurn(pacmanX, pacmanY, dest);
        if (temp == nullptr) {
            direction = STOP;
        } else {
            setDestination(temp);
        }
    }
}

int Ghosts::oppositeDirection(int direction) {
    switch (direction) {
    case UP:
        return DOWN;
    case DOWN:
        return UP;
    case LEFT:
        return RIGHT;
    case RIGHT:
        return LEFT;
    default:
        return STOP;
    }
}

std::shared_ptr<Intersection> Ghosts::makeTurn(int pacmanX, int pacmanY,
                                               std::shared_ptr<Intersection> dest) {
    if (dest != nullptr) {
        x = dest->getX();
        y = dest->getY();
        std::vector<std::shared_ptr<Intersection>> options = dest->getOptions();
        std::shared_ptr<Intersection> closest = nullptr;
        float closest_dist = 100000;
        Tile target;
        switch (mode) {
        case SCATTER:
            target = scatterTarget;
            break;
        case CHASE:
            target = getGoalTile(pacmanX, pacmanY);
            break;
        case FRIGHTENED:
            target.x = std::uniform_int_distribution<int>(0, 27)(rng);
            target.y = std::uniform_int_distribution<int>(3, 34)(rng);
            break;
        case EYES:
            target.x = getOrig().x;
            target.y = getOrig().y;
            break;
        default:
            break;
        }
        int x_goal = target.x * CELL_SIZE;
        int y_goal = target.y * CELL_SIZE;
        for (auto option : options) {
            // remove the option to turn around
            int dir = dest->getDirection(option);
            if (dir == oppositeDirection(direction)) {
                continue;
            }
            float dist = sqrt(pow(option->getX() - x_goal, 2) + pow(option->getY() - y_goal, 2));
            if (dist < closest_dist) {
                closest_dist = dist;
                closest = option;
            }
        }
        direction = dest->getDirection(closest);
        return closest;
    }
    return nullptr;
}