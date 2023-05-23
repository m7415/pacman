#include "Game.h"

Game::Game() {
    renderer = std::make_unique<Renderer>();
    score = 0;
    lives = 4;
    game_start = SDL_GetTicks();
    maze = Maze();
    std::shared_ptr<Intersection> dest_pac = maze.getIntersection(45);
    std::shared_ptr<Intersection> dest_ghosts = maze.getIntersection(23);
    std::shared_ptr<Intersection> dest_ghosts2 = maze.getIntersection(24);
    pacman =
        std::make_shared<Pacman>(14 * CELL_SIZE, 26 * CELL_SIZE + CELL_CENTER, RIGHT, dest_pac);
    ghosts = std::vector<std::shared_ptr<Ghosts>>();
    ghosts.push_back(
        std::make_shared<Blinky>(14 * CELL_SIZE, 14 * CELL_SIZE + CELL_CENTER, LEFT, dest_ghosts));
    ghosts.push_back(
        std::make_shared<Pinky>(14 * CELL_SIZE, 17 * CELL_SIZE + CELL_CENTER, LEFT, dest_ghosts));
    ghosts.push_back(
        std::make_shared<Inky>(12 * CELL_SIZE, 17 * CELL_SIZE + CELL_CENTER, RIGHT, dest_ghosts2));
    ghosts.push_back(
        std::make_shared<Clyde>(16 * CELL_SIZE, 17 * CELL_SIZE + CELL_CENTER, LEFT, dest_ghosts));
}

Game::~Game() {}

void Game::setPlayerDirection(int direction) {
    playerDirection = direction;
    pacman->setPlayerDirection(direction);
    return;
}

void Game::handlePacgums() {
    int col = pacman->getX() / CELL_SIZE;
    int row = pacman->getY() / CELL_SIZE;
    for (std::shared_ptr<Gomme> gomme : maze.getGommes()) {
        int gomme_col = gomme->getX() / CELL_SIZE;
        int gomme_row = gomme->getY() / CELL_SIZE;
        if (col == gomme_col && row == gomme_row) {
            if (gomme->getType() == GUM) {
                score += 10;
            } else if (gomme->getType() == PACGUM) {
                score += 50;
                for (std::shared_ptr<Ghosts> ghost : ghosts) {
                    ghost->setMode(FRIGHTENED);
                }
            }
            maze.clearGomme(gomme);
            nb_gommes--;
            last_gum_eaten = SDL_GetTicks();
            pacman->setEating(true);
        }
    }
}

int Game::handleGhosts() {
    int col = pacman->getX() / CELL_SIZE;
    int row = pacman->getY() / CELL_SIZE;
    for (std::shared_ptr<Ghosts> ghost : ghosts) {
        int ghost_col = ghost->getX() / CELL_SIZE;
        int ghost_row = ghost->getY() / CELL_SIZE;
        if (col == ghost_col && row == ghost_row) {
            if (ghost->getMode() == FRIGHTENED) {
                score += 100; // TODO: add combo
                ghost->setMode(EYES);
            } else if (ghost->getMode() == EYES) {
                continue;
            } else {
                return LOSE;
            }
        }
    }
    return PLAYING;
}

int Game::reset() {
    renderer->render(maze, pacman, ghosts, score, LOSE, lives);
    lives--;
    if (lives == 0) {
        return GAMEOVER;
    }
    std::shared_ptr<Intersection> dest_pac = maze.getIntersection(45);
    std::shared_ptr<Intersection> dest_ghosts = maze.getIntersection(23);
    pacman =
        std::make_shared<Pacman>(14 * CELL_SIZE, 26 * CELL_SIZE + CELL_CENTER, RIGHT, dest_pac);
    ghosts = std::vector<std::shared_ptr<Ghosts>>();
    ghosts.push_back(
        std::make_shared<Blinky>(14 * CELL_SIZE, 14 * CELL_SIZE + CELL_CENTER, LEFT, dest_ghosts));
    ghosts.push_back(
        std::make_shared<Pinky>(14 * CELL_SIZE, 17 * CELL_SIZE + CELL_CENTER, UP, dest_ghosts));
    ghosts.push_back(
        std::make_shared<Inky>(12 * CELL_SIZE, 17 * CELL_SIZE + CELL_CENTER, UP, dest_ghosts));
    ghosts.push_back(
        std::make_shared<Clyde>(16 * CELL_SIZE, 17 * CELL_SIZE + CELL_CENTER, UP, dest_ghosts));
    return CONTINUE;
}

int Game::update(int state) {
    if (state == PLAYING) {
        pacman->move();
        for (std::shared_ptr<Ghosts> ghost : ghosts) {
            ghost->move(pacman->getX(), pacman->getY(), ghost->getDestination(), 244 - nb_gommes);
        }
        // change the mode of the ghosts depending on the time using the modes vector
        int time = SDL_GetTicks() - game_start;
        int mode = -1;
        for (size_t i = 0; i < modes.size(); i++) {
            if (time > mode_times[i]) {
                mode = modes[i];
            }
        }
        if (mode != -1) {
            modes.erase(modes.begin());
            mode_times.erase(mode_times.begin());
            for (std::shared_ptr<Ghosts> ghost : ghosts) {
                ghost->setMode(mode);
            }
        }
    }
    if (SDL_GetTicks() - last_gum_eaten > 500) {
        pacman->setEating(false);
    }
    renderer->render(maze, pacman, ghosts, score, state, lives);
    if (handleGhosts() == LOSE) {
        return LOSE;
    }
    handlePacgums();
    if (nb_gommes == 0) {
        return WIN;
    }
    return state;
}
