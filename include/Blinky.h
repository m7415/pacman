#ifndef BLINKY_H
#define BLINKY_H

#include "Entity.h"
#include "Ghosts.h"
#include "constants.h"
#include <iostream>

class Blinky : public Ghosts {
  public:
    Blinky(float x, float y, int direction, std::shared_ptr<Intersection> destination);
    ~Blinky();
    std::shared_ptr<Intersection> getDestination();
    void setDestination(std::shared_ptr<Intersection> dest);
    Tile getOrig();

  private:
    std::shared_ptr<Intersection> dest;
    /**
     * @brief Get the Goal Tile object
     *
     * @details Blinky's goal tile is pacman's current tile.
     *
     * @param pacmanX
     * @param pacmanY
     * @return Tile
     */
    Tile getGoalTile(int pacmanX, int pacmanY);
    Tile scatterTarget;
};

#endif /* BLINKY_H */