#ifndef INKY_H
#define INKY_H

#include "Entity.h"
#include "Ghosts.h"
#include "constants.h"
#include <iostream>

class Inky : public Ghosts {
  public:
    Inky(float x, float y, int direction, std::shared_ptr<Intersection> destination);
    ~Inky();
    std::shared_ptr<Intersection> getDestination();
    void setDestination(std::shared_ptr<Intersection> dest);
    Tile getOrig();

  private:
    std::shared_ptr<Intersection> dest;
    /**
     * @brief Get the Goal Tile object
     *
     * @details Inky's goal tile is 2 tiles ahead of Pacman's current tile, and then
     * the vector from Blinky's current tile to that tile is doubled.
     * However, this behaviour is not implemented yet.
     *
     * @param pacmanX
     * @param pacmanY
     * @return Tile
     */
    Tile getGoalTile(int pacmanX, int pacmanY);
    Tile scatterTarget;
};

#endif /* INKY_H */