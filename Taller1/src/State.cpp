#include "State.h"


State::State(StateMachineApp *app)
{
	this->app = app;
}


State::~State(void)
{
}

void State::setup(){
}
void State::update(){
}
void State::draw(){
	cout <<"State::draw"<<endl;
	ofSetColor(0xFF, 0xFF, 0xFF);
	ofCircle(150,150,100);
}

void State::exit(){}
void State::keyPressed(int key){}
void State::keyReleased(int key){}
void State::mouseMoved(int x, int y){}
void State::mouseDragged(int x, int y, int button){}
void State::mousePressed(int x, int y, int button){}
void State::mouseReleased(int x, int y, int button){}