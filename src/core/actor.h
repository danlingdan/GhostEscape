#pragma once
#include "object_world.h"

class Stats;
class Actor : public ObjectWorld
{
protected:
    Stats *stats_ = nullptr;
    glm::vec2 velocity_ = glm::vec2(0, 0);
    float max_speed_ = 100.0f;

public:
    virtual void move(float dt);

    void takeDamage(float damage);
    bool isAlive();

    // getter and setter
    auto getStats() const { return stats_; }
    void setStats(Stats *stats) { stats_ = stats; }
    auto getVelocity() const { return velocity_; }
    auto getMaxSpeed() const { return max_speed_; }
    void setVelocity(const glm::vec2 &velocity) { velocity_ = velocity; }
    void setMaxSpeed(float max_speed) { max_speed_ = max_speed; }
};