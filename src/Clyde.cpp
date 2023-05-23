#include "Clyde.h"

Clyde::Clyde(float x, float y, int direction, std::shared_ptr<Intersection> destination)
    : Ghosts(x, y, direction, {0, Y_CELLS - 1}, 32) {
    sprites = {
        {457, 113, 13, 13}, {473, 113, 13, 13}, // RIGHT
        {489, 113, 13, 13}, {505, 113, 13, 13}, // LEFT
        {521, 113, 13, 13}, {537, 113, 13, 13}, // UP
        {553, 113, 13, 13}, {569, 113, 13, 13}, // DOWN
        {585, 65, 13, 13},  {601, 65, 13, 13},  // FRIGHTENED
        {617, 65, 13, 13},  {633, 65, 13, 13},  //
        {585, 81, 13, 13},  {601, 81, 13, 13},  // EYES
        {617, 81, 13, 13},  {633, 81, 13, 13}   //
    };
    dest = destination;
}

Clyde::~Clyde() {}

std::shared_ptr<Intersection> Clyde::getDestination() { return dest; }

Tile Clyde::getOrig() {
    return {14, 14};
    // return {16, 17};
}

void Clyde::setDestination(std::shared_ptr<Intersection> destination) { dest = destination; }

Tile Clyde::getGoalTile(int pacmanX, int pacmanY) {
    Tile goal;
    float dist = sqrt(pow((pacmanX - x), 2) + pow((pacmanY - y), 2)) / CELL_SIZE;
    if (dist > 8) {
        goal.x = pacmanX / CELL_SIZE;
        goal.y = pacmanY / CELL_SIZE;
    } else {
        goal.x = scatterTarget.x;
        goal.y = scatterTarget.y;
    }
    return goal;
}