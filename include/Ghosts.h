#ifndef GHOSTS_H
#define GHOSTS_H

#include "Entity.h"
#include "constants.h"
#include <iostream>
#include <random>

/**
 * @brief Ghosts class
 *
 * @details this class is used to store the ghosts. It is an abstract class.
 *
 */
class Ghosts : public Entity {
  public:
    Ghosts(float x, float y, int direction, Tile target, int dotCounter);
    ~Ghosts();
    /**
     * @brief move the ghost
     *
     * @details this method is used to move the ghost. It calls the makeTurn method to make the
     * ghost turn at an intersection.
     *
     * @param pacmanX
     * @param pacmanY
     * @param dest
     * @param dotEaten
     */
    void move(int pacmanX, int pacmanY, std::shared_ptr<Intersection> dest, int dotEaten);
    /**
     * @brief render the ghost
     *
     * @details this method is used to render the ghost. It calls the getSprite method to get the
     * correct sprite for the ghost.
     *
     * @param frame
     * @param renderer
     * @param texture
     */
    void render(int frame, SDL_Renderer *renderer, SDL_Texture *texture);
    virtual std::shared_ptr<Intersection> getDestination() = 0;
    virtual void setDestination(std::shared_ptr<Intersection> dest) = 0;
    void setMode(int mode);
    int getMode();
    virtual Tile getOrig() = 0;

  protected:
    std::vector<SDL_Rect> sprites;
    SDL_Rect getSprite(int frame, int direction);
    int mode = SCATTER;
    int previousMode = SCATTER;
    /**
     * @brief return the next intersection
     *
     * @details this method is used to return the next intersection. It also updates the coordinates
     * of the ghost. It calls the getGoalTile method to get the goal tile of the ghost.
     * The behaviour of the ghost depends on the mode it is in.
     * @param pacmanX
     * @param pacmanY
     * @param dest
     * @return std::shared_ptr<Intersection>
     */
    std::shared_ptr<Intersection> makeTurn(int pacmanX, int pacmanY,
                                           std::shared_ptr<Intersection> dest);
    virtual Tile getGoalTile(int pacmanX, int pacmanY) = 0;
    Tile scatterTarget;
    int oppositeDirection(int direction);
    std::mt19937 rng;
    Uint32 modeTimer = 0;
    int dotCounter;
    bool isFree = false;
};

#endif /* GHOSTS_H */