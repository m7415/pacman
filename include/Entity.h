#ifndef ENTITY_H
#define ENTITY_H

#include "Maze.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <vector>

/**
 * @brief Entity class
 *
 * @details this class is used to store the entities (pacman and ghosts).
 * It is an abstract class.
 *
 */
class Entity {
  public:
    Entity(float x, float y, int direction);
    /**
     * @brief render the entity
     *
     * @details this method is used to render the entity. It is a pure virtual method. It is
     * implemented in the subclasses.
     *
     * @param frame
     * @param renderer
     * @param texture
     */
    virtual void render(int frame, SDL_Renderer *renderer, SDL_Texture *texture) = 0;
    void setDirection(int d);
    float getX() const;
    float getY() const;

  protected:
    float x;
    float y;
    float speed;
    int direction;
    std::vector<SDL_Rect> sprites;
    virtual SDL_Rect getSprite(int frame, int direction) = 0;
    /**
     * @brief return wether the entity is at an intersection
     *
     * @param dest
     * @return true
     * @return false
     */
    bool isAtIntersection(std::shared_ptr<Intersection> dest);
};

#endif /* ENTITY_H */
