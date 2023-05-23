#ifndef PACMAN_H
#define PACMAN_H

#include "Entity.h"
#include <iostream>

/**
 * @brief Pacman class
 *
 * @details this class is used to store the pacman entity.
 * It is a subclass of Entity.
 *
 */
class Pacman : public Entity {
  public:
    Pacman(float x, float y, int direction, std::shared_ptr<Intersection> destination);
    ~Pacman();
    /**
     * @brief move the pacman
     *
     * @details this method is used to move the pacman. It calls the makeTurn method when the pacman
     * is at an intersection.
     *
     */
    void move();
    /**
     * @brief render the pacman
     *
     * @details this method is used to render the pacman. It calls the getSprite method to get the
     * correct sprite for the pacman.
     *
     * @param frame
     * @param renderer
     * @param texture
     */
    void render(int frame, SDL_Renderer *renderer, SDL_Texture *texture);
    void setPlayerDirection(int d);
    int getX() const;
    int getY() const;
    void setEating(bool e);
    bool getEating() const;

  private:
    std::shared_ptr<Intersection> dest;
    std::vector<SDL_Rect> sprites;
    SDL_Rect getSprite(int frame, int direction);
    /**
     * @brief return the next intersection
     *
     * @details this method is used to return the next intersection. It also updates the coordinates
     * of the pacman.
     * @return std::shared_ptr<Intersection>
     */
    std::shared_ptr<Intersection> makeTurn();
    int playerDirection = RIGHT;
    SDL_Rect lastSprite = {489, 1, 13, 13};
    bool isEating = false;
};

#endif /* PACMAN_H */