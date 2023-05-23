#pragma once

#include "Game.h"
#include "Renderer.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

/**
 * @brief This class is responsible for running the game loop and processing
 * events
 *
 *
 */

class GameController {
  public:
    /**
     * @brief Construct a new Game Controller object
     *
     */
    GameController();
    ~GameController();

    /**
     * @brief This function runs the game loop
     *
     * @details  This function runs the game loop by calling the run function
     * from the game class. It also processes events using the processEvent
     * function.
     *
     */
    void run();

    /**
     * @brief This function processes events
     *
     * @details This handle the quiting of the game and the user input
     *
     * @param event
     */
    void processEvent(const SDL_Event &event);

  private:
    bool quitGame;
    std::unique_ptr<Game> game;
    int state = STARTING;
};
