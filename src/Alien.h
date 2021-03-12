#pragma once

#include "AbstractGameObject.h"

class ofApp;

class Alien : public AbstractGameObject{
	private:
		bool direita = true;
		bool isTarget;
		float dado;
		float speed = 0;
		float interval = 0;
		ofSoundPlayer som;

	public:
		Alien();
		virtual void draw() const override;
		virtual void hit(const shared_ptr<GameObject> other) override;
		void flipTarget();
		void update(float s);
};