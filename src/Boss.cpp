#include "Boss.h"
#include "ofMain.h"
#include "GameManager.h"
#include "AlienShot.h"
#include "BossMissil.h"

Boss::Boss() : AbstractGameObject("image/MartianSaucer.gif"), isTarget(false) {
	som.load("audio/destroyerShot.wav");
	som_m.load("audio/destroyerSpecial.wav");
	som_e.load("audio/explosion.wav");
}
/*
void Boss::hit(const shared_ptr<GameObject> other) {
	auto shot = std::dynamic_pointer_cast<AlienShot>(other);
	auto missil = std::dynamic_pointer_cast<BossMissil>(other);
	if (shot || missil) return;

	if (vidas <= 0) {
		kill();
	}
}
*/
bool Boss::vivo = true;
void Boss::flipTarget() { isTarget = !isTarget; }

void Boss::draw() const {
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

void Boss::update(float s) {
	if (direita) {
		speed = 200;
		if (pos.x + sprite.getWidth() / 2 >= ofGetWidth()) direita = !direita;
	}
	else {
		speed = -200;
		if (pos.x - sprite.getWidth() / 2 <= 0) direita = !direita;
	}
	pos.x += speed * s;

	intervalo = rand() % 50;
	if (intervalo == 0) {
		som.play();
		som.setVolume(0.1f);
		intervalo = 0;
		auto shot = std::make_shared<AlienShot>();
		shot->setup(pos);
		MANAGER.add(shot);
	}

	intervalo_missil = rand() % 200;
	if (intervalo_missil == 0) {
		som_m.play();
		som_m.setVolume(0.1f);
		intervalo_missil = 0;
		auto missil = std::make_shared<BossMissil>();
		missil->setup(pos);
		MANAGER.add(missil);
	}

	if (vidas <= 0) {
		kill();
		som_e.play();
		som_e.setVolume(0.1f);
		Boss::vivo = false;
	}
}