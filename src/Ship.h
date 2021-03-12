#pragma once

#include "Shot.h"
#include "Missil.h"
#include "AbstractGameObject.h"

class Ship : public AbstractGameObject {
	private:
		float interval = 0;
		float missilInterval = 0;
		ofSoundPlayer som;
		ofSoundPlayer som_m;
		ofSoundPlayer som_e;


	public:
		static bool vivo;
		static float posx;
		int vidas = 10;
		Ship();
		void update(float s);
		virtual void draw() const override;
		virtual void hit(const shared_ptr<GameObject> other) override;
};