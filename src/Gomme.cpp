#include "Gomme.h"

Gomme::Gomme(int y, int x, SDL_Rect sprite) : x_pixel(x), y_pixel(y), sprite(sprite) {
    if (sprite.y == SRC_GUM.y) {
        type = GUM;
    } else if (sprite.y == SRC_PACGUM.y) {
        type = PACGUM;
    } else {
        type = UNDEFINED;
    }
}

Gomme::~Gomme() {}

int Gomme::getX() const { return x_pixel; }

int Gomme::getY() const { return y_pixel; }

int Gomme::getType() const { return type; }

void Gomme::render(SDL_Renderer *renderer, SDL_Texture *texture) {
    SDL_Rect dest;
    dest.w = 16;
    dest.h = 16;
    dest.x = x_pixel - dest.w / 2;
    dest.y = y_pixel - dest.h / 2;
    SDL_RenderCopy(renderer, texture, &sprite, &dest);
}