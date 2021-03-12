#include "AbstractGameObject.h"

AbstractGameObject::AbstractGameObject(const string& spriteName) : spriteName(spriteName), alive(true) {}

int AbstractGameObject::cont_alien = 32;

void AbstractGameObject::setup(ofVec2f pos) {
	this->pos = pos;

	sprite.load(spriteName);
	sprite.setAnchorPercent(.5f, .5f);
}

void AbstractGameObject::update(float s) {}

void AbstractGameObject::draw() const {
	ofSetColor(255, 255, 255, 255);
	sprite.draw(pos);
}

ofVec2f AbstractGameObject::getPos() const { return pos;  }

ofRectangle AbstractGameObject::getBounds() const {
	float hw = sprite.getWidth() / 2;
	float hh = sprite.getHeight() / 2;
	ofRectangle bounds(pos.x - hw, pos.y - hh, sprite.getWidth(), sprite.getHeight());
	return bounds;
}

void AbstractGameObject::hit(const std::shared_ptr<GameObject> other) {}

AbstractGameObject::~AbstractGameObject() {}

void AbstractGameObject::kill() {
	alive = false;
}

bool AbstractGameObject::finished() const {
	return !alive;
}

void AbstractGameObject::menos_um() {
	AbstractGameObject::cont_alien--;
}