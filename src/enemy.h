#pragma once
#include "player.h"

class Enemy : public Actor
{
    Player *target = nullptr;

public:
    void aim_target(Player *target);
};