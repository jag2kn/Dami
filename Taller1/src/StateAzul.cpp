#include "StateAzul.h"


StateAzul::StateAzul(StateMachineApp *app):State(app)
{
}


StateAzul::~StateAzul(void)
{
}

void StateAzul::setup(){
}

void StateAzul::draw(){
	ofSetColor(0x55, 0x55, 0xFF);
	ofCircle(150,150,100);

}
void StateAzul::update(){
}

void StateAzul::exit(){}
void StateAzul::keyPressed(int key){}
void StateAzul::keyReleased(int key){}
void StateAzul::mouseMoved(int x, int y){}
void StateAzul::mouseDragged(int x, int y, int button){}
void StateAzul::mousePressed(int x, int y, int button){}
void StateAzul::mouseReleased(int x, int y, int button){}