#include "Inky.h"

Inky::Inky(float x, float y, int direction, std::shared_ptr<Intersection> destination)
    : Ghosts(x, y, direction, {X_CELLS - 1, Y_CELLS - 1}, 17) {
    sprites = {
        {457, 97, 13, 13}, {473, 97, 13, 13}, // RIGHT
        {489, 97, 13, 13}, {505, 97, 13, 13}, // LEFT
        {521, 97, 13, 13}, {537, 97, 13, 13}, // UP
        {553, 97, 13, 13}, {569, 97, 13, 13}, // DOWN
        {585, 65, 13, 13}, {601, 65, 13, 13}, // FRIGHTENED
        {617, 65, 13, 13}, {633, 65, 13, 13}, //
        {585, 81, 13, 13}, {601, 81, 13, 13}, // EYES
        {617, 81, 13, 13}, {633, 81, 13, 13}  //
    };
    dest = destination;
}

Inky::~Inky() {}

std::shared_ptr<Intersection> Inky::getDestination() { return dest; }

Tile Inky::getOrig() {
    return {14, 14};
    // return {12, 17};
}

void Inky::setDestination(std::shared_ptr<Intersection> destination) { dest = destination; }

Tile Inky::getGoalTile(int pacmanX, int pacmanY) {
    Tile goal;
    // TODO: Implement this function correctly
    goal.x = pacmanX / CELL_SIZE;
    goal.y = pacmanY / CELL_SIZE;
    return goal;
}