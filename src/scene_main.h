#pragma once
#include "core/scene.h"

class Player;
class SceneMain : public Scene
{

    Player *player_ = nullptr;

public:
    SceneMain() = default;
    virtual ~SceneMain() = default;

    virtual void init() override;
    virtual void handleEvents(SDL_Event &event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

private:
    void renderBackground();
};