#include "StateMachineApp.h"

//--------------------------------------------------------------
void StateMachineApp::setup(){
	ofBackground(0,0,0);
}

//--------------------------------------------------------------
void StateMachineApp::update(){


}

//--------------------------------------------------------------
void StateMachineApp::draw(){
	cout <<"StateMachineApp::draw"<<endl;
}

//--------------------------------------------------------------
void StateMachineApp::keyPressed(int key){

}

//--------------------------------------------------------------
void StateMachineApp::keyReleased(int key){

}

//--------------------------------------------------------------
void StateMachineApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void StateMachineApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void StateMachineApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void StateMachineApp::mouseReleased(int x, int y, int button){

}


void StateMachineApp::exit(){
}

StateMachineApp::~StateMachineApp(){
	delete[]states;
}

void StateMachineApp::goToState(int i){
	currentState = states[i];
}

