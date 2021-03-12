#pragma once

#include <memory>
#include "ofMain.h"

class GameObject {
	public:
		virtual void setup(ofVec2f pos) = 0;
		virtual void update(float s) = 0;
		virtual void draw() const = 0;
		virtual bool finished() const = 0;

		virtual ofVec2f getPos() const = 0;
		virtual ofRectangle getBounds() const = 0;
		virtual void hit(const std::shared_ptr<GameObject> other) = 0;
		virtual ~GameObject() {};
};