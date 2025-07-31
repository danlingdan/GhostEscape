#pragma once
#include "../object_affiliate.h"
#include <string>

struct Texture
{
    SDL_Texture *texture = nullptr;
    SDL_FRect src_rect = {};
    float angle = 0.0f;
    bool is_flip = false;
    Texture() = default;
    Texture(const std::string &file_path);
};

class Sprite : public ObjectAffiliate
{
protected:
    Texture texture_;

public:
    Sprite() = default;

    static Sprite *addSpriteChild(ObjectScreen *parent, const std::string &file_path, float scale = 1.0f);

    virtual void render() override;

    void setScale(float scale) { size_ *= scale; }

    // getter and setter
    auto getTexture() const { return texture_; }
    virtual void setTexture(const Texture &texture);
    auto getSize() const { return size_; }
    void setSize(const glm::vec2 &size) { size_ = size; }
    auto getOffset() const { return offset_; }
    void setOffset(const glm::vec2 &offset) { offset_ = offset; }
    auto getAngle() const { return texture_.angle; }
    void setAngle(float angle) { texture_.angle = angle; }
    auto isFlip() const { return texture_.is_flip; }
    void setFlip(bool flip) { texture_.is_flip = flip; }
};