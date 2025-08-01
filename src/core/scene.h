#pragma once
#include "object.h"
#include "object_world.h"
#include <glm/glm.hpp>
#include <vector>

class Scene : public Object
{
protected:
    glm::vec2 camera_position_ = glm::vec2(0);

    glm::vec2 world_size_ = glm::vec2(0);

    std::vector<ObjectWorld *> children_world_;
    std::vector<ObjectScreen *> children__screen_;

public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void init() override {}
    virtual void handleEvents(SDL_Event &event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

    // getter and setter
    auto worldToScreen(const glm::vec2 &world_position) const { return world_position - camera_position_; }
    auto screenToWorld(const glm::vec2 &screen_position) const { return screen_position + camera_position_; }
    auto getCameraPosition() const { return camera_position_; }
    void setCameraPosition(const glm::vec2 &camera_position);
    auto getWorldSize() const { return world_size_; }
    void setWorldSize(const glm::vec2 &world_size) { world_size_ = world_size; }

    virtual void addChild(Object *child) override;
    virtual void removeChild(Object *child) override;
};
