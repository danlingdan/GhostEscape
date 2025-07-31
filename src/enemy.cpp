#include "enemy.h"

void Enemy::aim_target(Player *target)
{
    auto direction = target->getPosition() - this->getPosition();
    direction = glm::normalize(direction);
    velocity_ = direction * max_speed_;
}