#include "AlienShot.h"
#include "Ship.h"

AlienShot::AlienShot() : AbstractGameObject("image/shot.png") {}

void AlienShot::update(float s) {
	this->pos.y += 500.0f * s;
	if (pos.y > ofGetHeight()) kill();
}

void AlienShot::hit(const std::shared_ptr<GameObject> other) {
	auto ship = std::dynamic_pointer_cast<Ship>(other);
	if (ship) kill();
}

void AlienShot::draw() const {
	bool show = true;

	if (show) {
		ofSetColor(0, 0, 255);
		ofDrawRectangle(getBounds());
	}

	AbstractGameObject::draw();
}