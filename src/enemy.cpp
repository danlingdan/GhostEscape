#include "enemy.h"
#include "core/affiliate/sprite_anim.h"
#include "raw/stats.h"

void Enemy::init()
{
    Actor::init();
    anim_normal_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-Sheet.png", 2.0f);
    anim_hurt_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghostHurt-Sheet.png", 2.0f);
    anim_die_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghostDead-Sheet.png", 2.0f);
    anim_hurt_->setActive(false);
    anim_die_->setActive(false);
    anim_die_->setIsLoop(false);

    current_anim_ = anim_normal_;
    coilder_ = Coilder::addCoilderChild(this, anim_normal_->getSize());
    stats_ = Stats::addStatsChild(this);
}

void Enemy::update(float dt)
{
    Actor::update(dt);
    aim_target(target_);
    move(dt);

    attack();
}

void Enemy::aim_target(Player *target)
{
    if (target == nullptr)
        return;
    auto direction = target->getPosition() - this->getPosition();
    direction = glm::normalize(direction);
    velocity_ = direction * max_speed_;
}

void Enemy::checkStates()
{
}

void Enemy::changeStates(States new_state)
{
    if (new_state == current_state_)
    {
        return;
    }
    current_anim_->setActive(false);
    switch (new_state)
    {
    case States::NORMAL:
        current_anim_ = anim_normal_;
        current_anim_->setActive(true);
        break;
    case States::HURT:
        current_anim_ = anim_hurt_;
        current_anim_->setActive(true);
        break;
    case States::DIE:
        current_anim_ = anim_die_;
        current_anim_->setActive(true);
        break;
    }

    current_state_ = new_state;
}

void Enemy::remove()
{
    if (anim_die_->getIsFinish())
    {
        need_remove_ = true;
    }
}

void Enemy::attack()
{
    if (!coilder_ || target_->getCoilder() == nullptr)
    {
        return;
    }

    if (coilder_->isCoilding(target_->getCoilder()))
    {
        if (stats_ && target_->getStats())
        {
            target_->takeDamage(stats_->getDamage());
        }
        // SDL_Log("Coilder!");
    }
}
