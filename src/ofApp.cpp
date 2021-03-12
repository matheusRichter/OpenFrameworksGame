#include "ofApp.h"
#include <iostream>

#include "Ship.h"
#include "Alien.h"
#include "Shot.h"
#include "Boss.h"

#include "GameManager.h"

//--------------------------------------------------------------
void ofApp::setup(){
	background_sound.load("audio/back_sound.mp3");
	background_sound.play();
	background_sound.setVolume(.1f);

	background_image.load("image/fundo.png");
	gameover.load("image/gameover.png");
	win.load("image/win.jpg");

	
	auto ship = std::make_shared<Ship>();
	ship->setup(ofVec2f(500, 620));
	MANAGER.add(ship);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			auto alien = std::make_shared<Alien>();
			alien->setup(ofVec2f(100 + 100 * i, 100 + 75 * j));
			MANAGER.add(alien);
		}
	}

	/*auto boss = std::make_shared<Boss>();
	boss->setup(ofVec2f(512, 200));
	MANAGER.add(boss);*/

	MANAGER.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	MANAGER.update();

	if (AbstractGameObject::cont_alien <= 0) {
		auto boss = std::make_shared<Boss>();
		boss->setup(ofVec2f(512, 200));
		MANAGER.add(boss);
		AbstractGameObject::cont_alien = 1000;
	}

	

}

//--------------------------------------------------------------
void ofApp::draw(){
	background_image.draw(0,0);
	MANAGER.draw();

	if (!Ship::vivo) {
		ofClear(0);

		gameover.draw(ofGetWidth()/2 - gameover.getWidth()/2, ofGetHeight()/2 - gameover.getHeight()/2);
	}
	if (!Boss::vivo) {
		ofClear(0);
		win.draw(ofGetWidth() / 2 - win.getWidth() / 2, ofGetHeight() / 2 - win.getHeight() / 2);

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}