#include "GameController.h"

GameController::GameController() {
    quitGame = false;
    game = std::make_unique<Game>();
}

GameController::~GameController() {}

void GameController::processEvent(const SDL_Event &event) {
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
            quitGame = true;
            break;
        case SDLK_UP:
            game->setPlayerDirection(UP);
            break;

        case SDLK_DOWN:
            game->setPlayerDirection(DOWN);
            break;

        case SDLK_LEFT:
            game->setPlayerDirection(LEFT);
            break;

        case SDLK_RIGHT:
            game->setPlayerDirection(RIGHT);
            break;
        default:
            break;
        }
        break;
    case SDL_QUIT:
        quitGame = true;
        break;
    default:
        break;
    }
}

void GameController::run() {
    SDL_Event event;

    while (!quitGame) {
        while (SDL_PollEvent(&event)) {
            processEvent(event);
        }

        state = game->update(state);

        if (state == STARTING) {
            SDL_Delay(4000);
            state = PLAYING;
        }

        if (state == WIN) {
            std::cout << "You win!" << std::endl;
            quitGame = true;
        } else if (state == LOSE) {
            int gameOver = game->reset();
            if (gameOver == GAMEOVER) {
                std::cout << "Game Over!" << std::endl;
                quitGame = true;
            }
            state = PLAYING;
            SDL_Delay(1000);
        }

        SDL_Delay(1000 / FPS);
    }
    return;
}
