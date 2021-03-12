
#include <vector>

#include "BossMissil.h"
#include "GameManager.h"
#include "Ship.h"

BossMissil::BossMissil() : AbstractGameObject("image/destroyerShot.png") {}

void BossMissil::setup(ofVec2f pos)
{
    AbstractGameObject::setup(pos);

}

void BossMissil::update(float s)
{
    /*
    cout << target.lock() << endl;
    if (auto t = target.lock()) {
        cout << "target existe" << endl;
        cout << t->getPos().x << endl;
        if (this->pos.x < t->getPos().x) {
            cout << "foi pro lado" << endl;
            this->pos.x += 50.0f * s;
        }
        else if (this->pos.x > t->getPos().x) {
            this->pos.x -= 50.0f * s;
        }
    }
    */

    if (this->pos.x < Ship::posx) {
        cout << "foi pro lado" << endl;
        this->pos.x += 200.0f * s;
    }
    else if (this->pos.x > Ship::posx) {
        this->pos.x -= 200.0f * s;
    }

    this->pos.y += 150.0f * s;
    if (pos.y < 0) {
        kill();
    }
}

void BossMissil::hit(const std::shared_ptr<GameObject> other) {
    const auto ship = dynamic_pointer_cast<Ship>(other);
    if (ship) {
        kill();
    }
}

void BossMissil::draw() const {
    bool debug = false;
    if (debug) {
        ofSetColor(255, 0, 0);
        ofDrawRectangle(getBounds());
    }
    AbstractGameObject::draw();
}
