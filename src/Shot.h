#pragma once

#include "AbstractGameObject.h"

class Shot : public AbstractGameObject {
	public:
		Shot();
		void update(float s) override;
		virtual void hit(const std::shared_ptr<GameObject> other) override;
		virtual void draw() const override;
};