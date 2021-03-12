#pragma once

#include "AbstractGameObject.h"

class Boss : public AbstractGameObject {
private:
	bool direita = true;
	bool isTarget;
	float speed = 0;
	int intervalo;
	int intervalo_missil;
	ofSoundPlayer som;
	ofSoundPlayer som_m;
	ofSoundPlayer som_e;

public:
	static bool vivo;
	int vidas = 50;
	Boss();
	virtual void draw() const override;
	//virtual void hit(const shared_ptr<GameObject> other) override;
	void flipTarget();
	void update(float s);
};

