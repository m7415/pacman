#ifndef RENDERER_H
#define RENDERER_H

#include "Entity.h"
#include "Ghosts.h"
#include "Gomme.h"
#include "Maze.h"
#include "Pacman.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <memory>

/**
 * @brief The Renderer class
 *
 * @details This class is responsible for rendering the game. It contains all the functions
 * related to rendering the game and the game elements. It also contains the functions
 * related to loading the resources.
 *
 */
class Renderer {
  public:
    /**
     * @brief Construct a new Renderer object
     *
     * @details This constructor initializes the renderer by creating the window and the renderer.
     * It also loads the resources, and initializes the SDL, SDL_ttf and SDL_mixer libraries.
     *
     */
    Renderer();
    ~Renderer();

    /**
     * @brief This function renders the game
     *
     * @details This function renders the game by rendering the maze, the pacman, the ghosts,
     * the score and the lives.
     *
     * @param maze
     * @param pacman
     * @param ghosts
     * @param score
     * @param state
     * @param lives
     */
    void render(const Maze &maze, std::shared_ptr<Pacman> pacman,
                std::vector<std::shared_ptr<Ghosts>> ghosts, int score, int state, int lives);

    /**
     * @brief This function updates the screen
     *
     */
    void updateScreen();

  private:
    void createWindow();
    void createRenderer();
    void loadResources();
    void loadMusic();
    void drawScore(int score);
    void drawLives(int lives);
    void animateDeath(std::shared_ptr<Pacman> pacman);

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Surface *surface_bmp = nullptr;
    SDL_Texture *texture_bmp = nullptr;
    Mix_Music *music_start = nullptr;
    Mix_Music *music_death = nullptr;
    Mix_Music *music_chomp = nullptr;

    int screenWidth;
    int screenHeight;
    int frame = 0;
};

#endif /* RENDERER_H */