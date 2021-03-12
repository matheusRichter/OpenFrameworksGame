#pragma once

#include "AbstractGameObject.h"

class AlienShot : public AbstractGameObject {
public:
	AlienShot();
	void update(float s) override;
	virtual void hit(const std::shared_ptr<GameObject> other) override;
	virtual void draw() const override;
};

