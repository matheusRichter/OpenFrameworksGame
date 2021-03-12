#include "GameManager.h"
#include "Ship.h"
#include "Shot.h"
#include "AlienShot.h"
#include "Missil.h"
#include "BossMissil.h"



Ship::Ship() : AbstractGameObject("image/intruder.png") {
	som.load("audio/intruderShot.wav");
	som_m.load("audio/destroyerSpecial.wav");
	som_e.load("audio/explosion.wav");
}

bool Ship::vivo = true;
float Ship::posx;

void Ship::update(float s) {
	float speed = 0;
	if (pos.x >= sprite.getWidth()/2 && ofGetKeyPressed(OF_KEY_LEFT)) {
		speed = -300;
	} else if (pos.x + sprite.getWidth()/2 < ofGetWidth() && ofGetKeyPressed(OF_KEY_RIGHT)) {
		speed = 300;
	}
	pos.x += speed * s;
	posx = pos.x;

	interval += s;
	if (ofGetKeyPressed(' ') && interval > 0.3) {
		som.play();
		som.setVolume(0.1f);
		interval = 0;
		auto shot = std::make_shared<Shot>();
		shot->setup(pos);
		MANAGER.add(shot);
	}

	missilInterval += s;
	if ((ofGetKeyPressed('m') || ofGetKeyPressed('M')) && missilInterval > 3.0) {
		som_m.play();
		som_m.setVolume(0.1f);
		missilInterval = 0;
		auto missil = std::make_shared<Missil>();
		missil->setup(pos);
		MANAGER.add(missil);
	}
}

void Ship::draw() const {
	bool show = false; // mudar para 'true' se desejar mostrar o retungulo
	if (show) {
		ofSetColor(0, 255, 0); // pode ser alterado para a cor que desejar
		ofDrawRectangle(getBounds());
	}
	ofDrawBitmapString("vidas: " + std::to_string(vidas), 20, 20);
	AbstractGameObject::draw();
}

void Ship::hit(const shared_ptr<GameObject> other) {
	auto shotA = std::dynamic_pointer_cast<AlienShot>(other);
	auto shot = std::dynamic_pointer_cast<Shot>(other);
	auto missil = std::dynamic_pointer_cast<Missil>(other);
	auto missilBoss = std::dynamic_pointer_cast<BossMissil>(other);
	
	if (shotA)vidas--;
	if (missilBoss) vidas -= 3;

	if (shot || missil) return;
	som_e.play();
	som_e.setVolume(0.1f);
	draw();
	if (vidas <= 0) {
		kill();
		Ship::vivo = false;
	}
}