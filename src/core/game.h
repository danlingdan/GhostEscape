#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <glm/glm.hpp>
#include <string>
#include "asset_store.h"

struct Texture;
class Scene;

class Game
{
    Game() {};
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    bool is_running_ = true;

    glm::vec2 screen_size_ = glm::vec2(0);

    SDL_Window *window_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;

    Uint64 FPS_ = 60;
    Uint64 frame_delay_ = 0;
    float dt_ = 0.0f;

    Scene *current_scene_ = nullptr;

    AssetStore *asset_store_ = nullptr;

public:
    static Game &getInstance()
    {
        static Game instance;
        return instance;
    }

    void run();
    void init(std::string title, int width, int height);
    void handleEvents();
    void update(float dt);
    void render();
    void clean();

    void renderTexture(const Texture &texture, const glm::vec2 &position, const glm::vec2 &size);

    // 工具函数
    void drawGrid(const glm::vec2 &top_left, const glm::vec2 &botton_right, float grid_width, SDL_FColor fcolor);
    void drawBoundary(const glm::vec2 &top_left, const glm::vec2 &botton_right, float boundary_width, SDL_FColor fcolor);

    // getter
    auto getScreenSize() const { return screen_size_; }
    Scene *getCurrentScene() const { return current_scene_; }
    auto getAssetStore() const { return asset_store_; }

    // setter
};