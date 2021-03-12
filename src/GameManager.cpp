#include "GameManager.h"
#include "ofMain.h"

#include <algorithm>
using namespace std;

GameManager::GameManager(){}

GameManager& GameManager::getInstance() {
	static GameManager instance;
	return instance;
}

void GameManager::add(shared_ptr<GameObject> object) {
	objects.push_back(object);
}

void GameManager::setup() {}

void GameManager::update() {
	auto temp = objects;
	for (auto obj : temp) {
		obj->update(ofGetLastFrameTime());
	}

	objects.erase(
		remove_if(objects.begin(), objects.end(),
			[](shared_ptr<GameObject> obj) {return obj->finished(); }), objects.end()
	);

	for (int i = 0; i < objects.size() - 1; i++) {
		for (int j = i+1; j < objects.size(); j++) {
			auto obj1 = objects[i];
			auto obj2 = objects[j];

			if (obj1->getBounds().intersects(obj2->getBounds())) {
				obj1->hit(obj2);
				obj2->hit(obj1);
			}
		}
	}
}

void GameManager::draw() const {
	for (auto obj : objects) {
		obj->draw();
	}
}

const vector<shared_ptr<GameObject> >& GameManager::getObjects() const {
	return objects;
}