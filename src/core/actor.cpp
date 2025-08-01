#include "actor.h"
#include "scene.h"
#include "../raw/stats.h"

void Actor::move(float dt)
{
    setPosition(position_ + velocity_ * dt);
    position_ = glm::clamp(position_, glm::vec2(0), game_.getCurrentScene()->getWorldSize());
}

void Actor::takeDamage(float damage)
{
    if (!stats_)
    {
        return;
    }
    stats_->takeDamage(damage);
}

bool Actor::isAlive()
{
    if (!stats_)
    {
        return true;
    }
    else
    {
        return stats_->getIsAlive();
    }
}
