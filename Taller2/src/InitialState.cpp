#include "InitialState.h"

InitialState::InitialState(StateMachineApp* app) : State(app){	
}

void InitialState::setup(){
}

void InitialState::update(){
}

void InitialState::draw(){
	ofBackgroundGradient(ofColor(128), ofColor(0), OF_GRADIENT_CIRCULAR);
	ofDrawBitmapString(getStateName(), 100, 100);
}

string InitialState::getStateName(){
	return "InitialState";
}

void InitialState::keyPressed(int key){
}

void InitialState::keyReleased(int key){
}

void InitialState::mouseMoved(int x, int y ){
}

void InitialState::mousePressed(int x, int y, int button){
}

void InitialState::mouseReleased(int x, int y, int button){
}

void InitialState::in(){
}

void InitialState::out(){
}