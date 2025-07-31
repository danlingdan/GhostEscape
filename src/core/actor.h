#pragma once
#include "object_world.h"

class Actor : public ObjectWorld
{
protected:
    glm::vec2 velocity_ = glm::vec2(0, 0);
    float max_speed_ = 100.0f;

public:
    // getter and setter
    auto getVelocity() const { return velocity_; }
    auto getMaxSpeed() const { return max_speed_; }
    void setVelocity(const glm::vec2 &velocity) { velocity_ = velocity; }
    void setMaxSpeed(float max_speed) { max_speed_ = max_speed; }
};