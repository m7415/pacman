#include "Blinky.h"

Blinky::Blinky(float x, float y, int direction, std::shared_ptr<Intersection> destination)
    : Ghosts(x, y, direction, {X_CELLS - 3, 0}, 0) {
    sprites = {
        {457, 65, 13, 13}, {473, 65, 13, 13}, // RIGHT
        {489, 65, 13, 13}, {505, 65, 13, 13}, // LEFT
        {521, 65, 13, 13}, {537, 65, 13, 13}, // UP
        {553, 65, 13, 13}, {569, 65, 13, 13}, // DOWN
        {585, 65, 13, 13}, {601, 65, 13, 13}, // FRIGHTENED
        {617, 65, 13, 13}, {633, 65, 13, 13}, //
        {585, 81, 13, 13}, {601, 81, 13, 13}, // EYES
        {617, 81, 13, 13}, {633, 81, 13, 13}  //
    };
    dest = destination;
}

Blinky::~Blinky() {}

std::shared_ptr<Intersection> Blinky::getDestination() { return dest; }

Tile Blinky::getOrig() { return {14, 14}; }

void Blinky::setDestination(std::shared_ptr<Intersection> destination) { dest = destination; }

Tile Blinky::getGoalTile(int pacmanX, int pacmanY) {
    Tile goal;
    goal.x = pacmanX / CELL_SIZE;
    goal.y = pacmanY / CELL_SIZE;
    return goal;
}