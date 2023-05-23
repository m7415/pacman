#ifndef PINKY_H
#define PINKY_H

#include "Entity.h"
#include "Ghosts.h"
#include "constants.h"
#include <iostream>

class Pinky : public Ghosts {
  public:
    Pinky(float x, float y, int direction, std::shared_ptr<Intersection> destination);
    ~Pinky();
    std::shared_ptr<Intersection> getDestination();
    void setDestination(std::shared_ptr<Intersection> dest);
    Tile getOrig();

  private:
    std::shared_ptr<Intersection> dest;
    /**
     * @brief Get the Goal Tile object
     *
     * @details Pinky's goal tile is 4 tiles ahead of Pacman's current tile
     *
     * @param pacmanX
     * @param pacmanY
     * @return Tile
     */
    Tile getGoalTile(int pacmanX, int pacmanY);
    Tile scatterTarget;
};

#endif /* PINKY_H */