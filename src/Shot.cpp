#include "Shot.h"
#include "Alien.h"
#include "Boss.h"

Shot::Shot() : AbstractGameObject("image/intruderShot.png") {}

void Shot::update(float s) {
	this->pos.y -= 500.0f * s;
	if (pos.y < 0) kill();
}

void Shot::hit(const std::shared_ptr<GameObject> other) {
	auto alien = std::dynamic_pointer_cast<Alien>(other);
	if (alien) kill();
	auto boss = std::dynamic_pointer_cast<Boss>(other);
	if (boss) {
		kill();
		boss->vidas--;
	}
}

void Shot::draw() const {
	bool show = false;

	if (show) {
		ofSetColor(0, 0, 255);
		ofDrawRectangle(getBounds());
	}

	AbstractGameObject::draw();
}