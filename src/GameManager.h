#pragma once

#include <vector>
#include <random>
#include <memory>
#include "GameObject.h"

#define	MANAGER GameManager::getInstance()

class GameManager {
	private:
		std::mt19937 mt;
		std::vector<std::shared_ptr<GameObject> > objects;

		GameManager();

		GameManager(const GameManager&) = delete;
		GameManager& operator = (const GameManager&) = delete;

	public:
		static GameManager& getInstance();
		void add(std::shared_ptr<GameObject> object);
		void setup();
		void update();
		void draw() const;
		const std::vector<std::shared_ptr<GameObject> >& getObjects() const;

		template<class T>
		std::shared_ptr<T> getRandom() {
			std::vector<std::shared_ptr<T>> candidates;
			for (auto obj : MANAGER.getObjects()) {
				auto candidate = std::dynamic_pointer_cast<T>(obj);
				if (candidate) candidates.push_back(candidate);
			}
			
			if (candidates.size() == 0) return nullptr;

			std::uniform_int_distribution<int> dist(0, candidates.size() - 1);
			int idx = dist(mt);
			return candidates[idx];
		}
};