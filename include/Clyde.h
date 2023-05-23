#ifndef CLYDE_H
#define CLYDE_H

#include "Entity.h"
#include "Ghosts.h"
#include "constants.h"
#include <iostream>

class Clyde : public Ghosts {
  public:
    Clyde(float x, float y, int direction, std::shared_ptr<Intersection> destination);
    ~Clyde();
    std::shared_ptr<Intersection> getDestination();
    void setDestination(std::shared_ptr<Intersection> dest);
    Tile getOrig();

  private:
    std::shared_ptr<Intersection> dest;
    /**
     * @brief Get the Goal Tile object
     *
     * @details Clyde's goal tile is pacman's current tile if the distance between
     * Clyde and Pacman is greater than 8 tiles. Otherwise, Clyde's goal tile is
     * it's scatter target.
     *
     * @param pacmanX
     * @param pacmanY
     * @return Tile
     */
    Tile getGoalTile(int pacmanX, int pacmanY);
    Tile scatterTarget;
};

#endif /* CLYDE_H */