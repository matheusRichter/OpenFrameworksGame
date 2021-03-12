#pragma once

#include "ofMain.h"

#include "GameObject.h"

class AbstractGameObject : public GameObject{
	protected:
		string spriteName;
		ofVec2f pos;
		ofImage sprite;
		bool alive;

		virtual void kill();

	public:
		static int cont_alien;
		void menos_um();

		AbstractGameObject(const string& spriteName);

		AbstractGameObject(const AbstractGameObject&) = delete;
		AbstractGameObject& operator = (const AbstractGameObject&) = delete;

		virtual void setup(ofVec2f pos);
		virtual void update(float s);
		virtual void draw() const;
		virtual bool finished() const;

		virtual ofVec2f getPos() const;
		virtual ofRectangle getBounds() const;

		virtual void hit(const std::shared_ptr<GameObject> other);

		virtual ~AbstractGameObject();
};