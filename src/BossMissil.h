
#pragma once

#include "AbstractGameObject.h"

class Ship;

class BossMissil : public AbstractGameObject {
private:
    std::weak_ptr<Ship> target;
public:
    BossMissil();
    virtual void setup(ofVec2f pos) override;
    virtual void update(float s) override;
    virtual void hit(const std::shared_ptr<GameObject> other) override;
    virtual void draw() const override;
};
