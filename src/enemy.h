#pragma once
#include "player.h"

class Enemy : public Actor
{
    Player *target_ = nullptr;

    enum class States
    {
        NORMAL,
        HURT,
        DIE
    };
    States current_state_ = States::NORMAL;

    SpriteAnim *anim_normal_ = nullptr;
    SpriteAnim *anim_hurt_ = nullptr;
    SpriteAnim *anim_die_ = nullptr;
    SpriteAnim *current_anim_ = nullptr;

    float timer_ = 0.0f;

public:
    virtual void
    init() override;
    virtual void update(float dt) override;

    void aim_target(Player *target);

    void checkStates();
    void changeStates(States new_state);

    void remove();

    // getter and setter
    auto getTarget() const { return target_; }
    void setTarget(Player *target) { target_ = target; }
};