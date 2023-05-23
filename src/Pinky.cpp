#include "Pinky.h"

Pinky::Pinky(float x, float y, int direction, std::shared_ptr<Intersection> destination)
    : Ghosts(x, y, direction, {2, 0}, 7) {
    sprites = {
        {457, 81, 13, 13}, {473, 81, 13, 13}, // RIGHT
        {489, 81, 13, 13}, {505, 81, 13, 13}, // LEFT
        {521, 81, 13, 13}, {537, 81, 13, 13}, // UP
        {553, 81, 13, 13}, {569, 81, 13, 13}, // DOWN
        {585, 65, 13, 13}, {601, 65, 13, 13}, // FRIGHTENED
        {617, 65, 13, 13}, {633, 65, 13, 13}, //
        {585, 81, 13, 13}, {601, 81, 13, 13}, // EYES
        {617, 81, 13, 13}, {633, 81, 13, 13}  //
    };
    dest = destination;
}

Pinky::~Pinky() {}

std::shared_ptr<Intersection> Pinky::getDestination() { return dest; }

Tile Pinky::getOrig() {
    return {14, 14};
    // return {14, 17};
}

void Pinky::setDestination(std::shared_ptr<Intersection> destination) { dest = destination; }

Tile Pinky::getGoalTile(int pacmanX, int pacmanY) {
    Tile goal;
    goal.x = pacmanX / CELL_SIZE + 4;
    goal.y = pacmanY / CELL_SIZE + 4;
    return goal;
}