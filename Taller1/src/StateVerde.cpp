#include "StateVerde.h"


StateVerde::StateVerde(StateMachineApp *app):State(app)
{
//	this->app = app;
}


StateVerde::~StateVerde(void)
{
}

void StateVerde::setup(){
}
void StateVerde::update(){
}
void StateVerde::draw(){
	ofSetColor(0x55, 0xFF, 0x55);
	ofCircle(150,150,100);
}
void StateVerde::exit(){}
void StateVerde::keyPressed(int key){}
void StateVerde::keyReleased(int key){}
void StateVerde::mouseMoved(int x, int y){}
void StateVerde::mouseDragged(int x, int y, int button){}
void StateVerde::mousePressed(int x, int y, int button){}
void StateVerde::mouseReleased(int x, int y, int button){}