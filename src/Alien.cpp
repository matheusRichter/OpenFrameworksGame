#include "Alien.h"
#include "ofMain.h"
#include "GameManager.h"
#include "AlienShot.h"

Alien::Alien() : AbstractGameObject("image/prope.png"), isTarget(false) {
	som.load("audio/destroyerShot.wav");
}

void Alien::hit(const shared_ptr<GameObject> other) { 
	auto shot = std::dynamic_pointer_cast<AlienShot>(other);
	if (shot) return;
	kill();
	menos_um();
}

void Alien::flipTarget() { isTarget = !isTarget; }

void Alien::draw() const { 
	if (isTarget) {
		ofSetColor(255, 0, 0);
		ofDrawRectangle(getBounds());
	}
	bool show = false;
	if (show) {
		ofSetColor(0, 255, 0);
		ofDrawRectangle(getBounds());
	}
	AbstractGameObject::draw();
}

void Alien::update(float s) {

	interval += s;
	if (direita) {
		speed = 100;
		if (interval > 3.0) {
			direita = !direita;
			interval = 0;
		}
	}
	else {
		speed = -100;
		if (interval > 3.0) {
			direita = !direita;
			interval = 0;
		}
	}
	pos.x += speed * s;

	dado = rand() % 500 + 1;
	if (dado == 500) {
		som.play();
		som.setVolume(0.05f);
		auto shot = std::make_shared<AlienShot>();
		shot->setup(pos);
		MANAGER.add(shot);
	}
}