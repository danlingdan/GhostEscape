#pragma once
#include "object_screen.h"

class ObjectAffiliate : public Object
{
protected:
    ObjectScreen *parent_ = nullptr;
    glm::vec2 offset_ = glm::vec2(0, 0);
    glm::vec2 size_ = glm::vec2(0, 0);

public:
    // getter and setter
    auto getParent() const { return parent_; }
    void setParent(ObjectScreen *parent) { parent_ = parent; }
    auto getOffset() const { return offset_; }
    void setOffset(const glm::vec2 &offset) { offset_ = offset; }
    auto getSize() const { return size_; }
    void setSize(const glm::vec2 &size) { size_ = size; }
};