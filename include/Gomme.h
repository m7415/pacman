#ifndef GOMME_H
#define GOMME_H

#include "constants.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

/**
 * @brief Gomme class
 *
 * @details This class is responsible for storing the pacgum and the super pacgum. (or dots)
 * It also is responsible for rendering them.
 *
 */
class Gomme {
  public:
    Gomme(int x, int y, SDL_Rect sprite);
    ~Gomme();
    void render(SDL_Renderer *renderer, SDL_Texture *texture);
    int getX() const;
    int getY() const;
    int getType() const;

  private:
    int x_pixel;
    int y_pixel;
    SDL_Rect sprite;
    int type;
};

#endif /* GOMME_H */