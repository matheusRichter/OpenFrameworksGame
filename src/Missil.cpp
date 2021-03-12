#include <vector>

#include "Missil.h"
#include "Alien.h"
#include "Boss.h"
#include "GameManager.h"

Missil::Missil() : AbstractGameObject("image/destroyerShot.png") {}

void Missil::setup(ofVec2f pos)
{
    AbstractGameObject::setup(pos);

    auto alien = MANAGER.getRandom<Alien>();
    if (alien) {
        target = alien;
        alien->flipTarget();
    }

}

void Missil::update(float s)
{
    if (auto t = target.lock()) {
        if (this->pos.x < t->getPos().x) {
            this->pos.x += 50.0f * s;
        }
        else if (this->pos.x > t->getPos().x) {
            this->pos.x -= 50.0f * s;
        }
    }

    this->pos.y += -100.0f * s;
    if (pos.y < 0) {
        if (auto t = target.lock()) t->flipTarget();
        kill();
    }
}

void Missil::hit(const std::shared_ptr<GameObject> other) {
    const auto alien = dynamic_pointer_cast<Alien>(other);
    if (alien) {
        if (auto t = target.lock()) t->flipTarget();
        kill();
    }

    const auto boss = dynamic_pointer_cast<Boss>(other);
    if (boss) {
        if (auto t = target.lock()) t->flipTarget();
        kill();
        boss->vidas -= 3;
    }
}

void Missil::draw() const {
    bool debug = false;
    if (debug) {
        ofSetColor(255, 0, 0);
        ofDrawRectangle(getBounds());
    }
    AbstractGameObject::draw();
}