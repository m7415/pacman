#ifndef GAME_H
#define GAME_H

#include "Blinky.h"
#include "Clyde.h"
#include "Entity.h"
#include "Ghosts.h"
#include "Inky.h"
#include "Maze.h"
#include "Pacman.h"
#include "Pinky.h"
#include "Renderer.h"
#include "constants.h"
#include <iostream>
#include <memory>

/**
 * @brief Game class
 *
 * @details This class is the main class of the game. It contains all the game logic.
 * It is responsible for updating the game state and rendering the game.
 *
 */

class Game {
  public:
    /**
     * @brief Construct a new Game object
     *
     * @details This constructor initializes the game by creating the maze, the pacman and the
     * ghosts. It also initializes the renderer.
     *
     */
    Game();
    ~Game();

    /**
     * @brief This function updates the game state
     *
     * @details This function updates the game state by updating the pacman and the ghosts.
     * It also handles the collisions between the pacman and the ghosts.
     *
     * @param state The current state of the game (STARTING, PLAYING, GAMEOVER, WON)
     *
     * @return int The new state of the game
     */
    int update(int state);

    /**
     * @brief Set the player direction. This function is called when the user presses a key.
     *
     * @param d The direction of the player
     */
    void setPlayerDirection(int d);

    /**
     * @brief reset the game to a starting state, called when the player loses a life
     *
     * @return int The new state of the game
     */
    int reset();

  private:
    void handlePacgums();
    int handleGhosts();
    int playerDirection = RIGHT;
    Maze maze;
    std::shared_ptr<Pacman> pacman;
    std::vector<std::shared_ptr<Ghosts>> ghosts;
    int score;
    std::unique_ptr<Renderer> renderer;
    int nb_gommes = 244;
    int lives;
    Uint32 last_gum_eaten = 0;
    int level = 1;
    std::vector<int> mode_times = {7000, 27000, 34000, 54000, 59000, 79000, 84000};
    std::vector<int> modes = {CHASE, SCATTER, CHASE, SCATTER, CHASE, SCATTER, CHASE};
    Uint32 game_start;
};

#endif /* GAME_H */