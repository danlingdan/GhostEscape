#pragma once
#include "core/actor.h"
#include "core/scene.h"
#include "core/affiliate/sprite_anim.h"

class Player : public Actor
{
protected:
    SpriteAnim *sprite_idle_ = nullptr;
    SpriteAnim *sprite_move_ = nullptr;
    bool is_moving_ = false;

public:
    virtual void init() override;
    virtual void handleEvents(SDL_Event &event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

    void keyboardControl();
    void move(float dt);
    void syncCamera();

    void checkStates();
    void changStates(bool);
};