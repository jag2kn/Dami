#include "StateRojo.h"


StateRojo::StateRojo(StateMachineApp *app):State(app)
{
	
}

StateRojo::~StateRojo(void)
{
}

void StateRojo::setup(){
}
void StateRojo::update(){
}
void StateRojo::draw(){
	ofSetColor(0xFF, 0x55, 0x55);
	ofCircle(150,150,100);
}


void StateRojo::exit(){}
void StateRojo::keyPressed(int key){}
void StateRojo::keyReleased(int key){}
void StateRojo::mouseMoved(int x, int y){}
void StateRojo::mouseDragged(int x, int y, int button){}
void StateRojo::mousePressed(int x, int y, int button){}
void StateRojo::mouseReleased(int x, int y, int button){}