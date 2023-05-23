#include "Renderer.h"

void Renderer::createWindow() {
    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth,
                              screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Renderer::createRenderer() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Renderer::loadResources() {
    surface_bmp = SDL_LoadBMP("./assets/pacman_sprites.bmp");
    if (surface_bmp == nullptr) {
        std::cerr << "Failed to load resource file: " << SDL_GetError() << std::endl;
        exit(1);
    }

    texture_bmp = SDL_CreateTextureFromSurface(renderer, surface_bmp);
    if (texture_bmp == nullptr) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Renderer::loadMusic() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError()
                  << std::endl;
        exit(1);
    }

    music_start = Mix_LoadMUS("./assets/intro.wav");
    if (music_start == nullptr) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        exit(1);
    }

    music_death = Mix_LoadMUS("./assets/death.wav");
    if (music_death == nullptr) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        exit(1);
    }

    music_chomp = Mix_LoadMUS("./assets/chomp.wav");
    if (music_chomp == nullptr) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        exit(1);
    }
}

Renderer::Renderer() : screenWidth(SCREEN_WIDTH), screenHeight(SCREEN_HEIGHT) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (TTF_Init() < 0) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
        exit(1);
    }

    if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3) {
        std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        exit(1);
    }

    createWindow();
    createRenderer();
    loadResources();
    loadMusic();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

Renderer::~Renderer() {
    Mix_FreeMusic(music_start);
    Mix_FreeMusic(music_death);
    Mix_FreeMusic(music_chomp);
    SDL_DestroyTexture(texture_bmp);
    SDL_FreeSurface(surface_bmp);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

void Renderer::drawScore(int score) {
    std::string score_str = std::to_string(score);
    SDL_Color color = {255, 255, 255, 255};
    TTF_Font *font = TTF_OpenFont("./assets/arial.ttf", 24);
    if (font == nullptr) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        exit(1);
    }
    SDL_Surface *surface = TTF_RenderText_Solid(font, score_str.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect src = {0, 0, surface->w, surface->h};
    SDL_Rect dst = {7 * CELL_SIZE, CELL_SIZE, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, &src, &dst);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

    SDL_Surface *surface2 = TTF_RenderText_Solid(font, "Score : ", color);
    SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_Rect src2 = {0, 0, surface2->w, surface2->h};
    SDL_Rect dst2 = {CELL_SIZE, CELL_SIZE, surface2->w, surface2->h};
    SDL_RenderCopy(renderer, texture2, &src2, &dst2);
    SDL_FreeSurface(surface2);
    SDL_DestroyTexture(texture2);

    TTF_CloseFont(font);
}

void Renderer::drawLives(int lives) {
    SDL_Rect src = {473, 17, 13, 13};
    for (int i = 0; i < lives; i++) {
        SDL_Rect dst = {2 * (i + 1) * CELL_SIZE, 34 * CELL_SIZE + 2, 26, 26};
        SDL_RenderCopy(renderer, texture_bmp, &src, &dst);
    }
}

void Renderer::animateDeath(std::shared_ptr<Pacman> pacman) {
    std::vector<SDL_Rect> sprites = {{489, 1, 13, 13}, {505, 1, 13, 13}, {521, 1, 13, 13},
                                     {537, 1, 13, 13}, {553, 1, 13, 13}, {569, 1, 13, 13},
                                     {859, 1, 13, 13}, {601, 1, 13, 13}, {617, 1, 13, 13},
                                     {633, 1, 13, 13}, {649, 1, 13, 13}, {665, 1, 13, 13}};
    int x = (int)pacman->getX();
    int y = (int)pacman->getY();
    int width = 26;
    int height = 26;
    for (int i = 0; i < 12; i++) {
        SDL_Rect src = sprites[i];
        SDL_Rect dst = {x - width / 2, y - height / 2, width, height};
        SDL_RenderCopy(renderer, texture_bmp, &src, &dst);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
}

void Renderer::render(const Maze &maze, std::shared_ptr<Pacman> pacman,
                      std::vector<std::shared_ptr<Ghosts>> ghosts, int score, int state,
                      int lives) {

    SDL_RenderClear(renderer);

    // draw the maze background
    SDL_Rect src_bg = SRC_BG;
    SDL_Rect bg = BG;
    SDL_RenderCopy(renderer, texture_bmp, &src_bg, &bg);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // draw the score
    drawScore(score);

    // draw the lives
    drawLives(lives);

    // draw the gums
    for (std::shared_ptr<Gomme> gomme : maze.getGommes()) {
        gomme->render(renderer, texture_bmp);
    }

    // draw the ghosts
    if (state == PLAYING) {
        for (std::shared_ptr<Ghosts> ghost : ghosts) {
            ghost->render(frame, renderer, texture_bmp);
        }
    }

    // draw pacman
    if (state == PLAYING) {
        pacman->render(frame, renderer, texture_bmp);
    }

    updateScreen();

    // play the sounds
    if (state == STARTING) {
        Mix_PlayMusic(music_start, 1);
        SDL_Delay(1000);
    }

    if (state == LOSE) {
        Mix_PlayMusic(music_death, 1);
        SDL_Delay(500);
        animateDeath(pacman);
        SDL_Delay(1000);
    }

    if (state == PLAYING) {
        if (pacman->getEating() && (Mix_PlayingMusic() == 0)) {
            Mix_PlayMusic(music_chomp, 1);
        } else if (!pacman->getEating() && (Mix_PlayingMusic() == 1)) {
            Mix_HaltMusic();
        }
    }

    frame = (frame + 1) % 60;
}

void Renderer::updateScreen() { SDL_RenderPresent(renderer); }