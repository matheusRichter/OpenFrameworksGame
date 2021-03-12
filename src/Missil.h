//
//  Missile.hpp
//  BatalhaEstelar
//
//  Created by Vinicius Godoy de Mendon�a on 29/09/20.
//

#pragma once

#include "AbstractGameObject.h"


class Alien;

class Missil : public AbstractGameObject {
private:
    std::weak_ptr<Alien> target;
    
public:
    Missil();
    virtual void setup(ofVec2f pos) override;
    virtual void update(float s) override;
    virtual void hit(const std::shared_ptr<GameObject> other) override;
    virtual void draw() const override;
};
