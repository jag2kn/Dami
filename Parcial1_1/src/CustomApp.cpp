#include "CustomApp.h"
#include "InitialState.h"
#include "TransformationsState.h"

void CustomApp::setupInternal(){
	ofSetFrameRate(60);
}

void CustomApp::updateInternal(){
}

void CustomApp::drawInternal(){
}

void CustomApp::exitInternal(){
}

int CustomApp::getStateCount(){
	return NUM_STATES;
}

State* CustomApp::createState(int id){
	switch (id)	{
		case TRANSFORMATIONS_STATE:
			return new TransformationsState(this);
		case INITIAL_STATE:
			return new InitialState(this);
	}
	
	return NULL;
}

string CustomApp::getStateName(int id){
	return "";
}

bool CustomApp::isTransitionValid(State* from, State* to){
	if (
		from->getStateName()=="TransformationsState" &&
		to->getStateName()=="InitialState"
	){
		return true;
	}
	if (
		from->getStateName()=="InitialState" &&
		to->getStateName()=="TransformationsState"
	){
		return true;
	}

	return false;
}

void CustomApp::keyPressed(int key){
	
	if(key == 'n'){
		if (this->currentState->getStateName()=="TransformationsState"){
			goToState(INITIAL_STATE);
		}else{
			if (this->currentState->getStateName()=="InitialState")
				goToState(TRANSFORMATIONS_STATE);
		}
	}else{
		StateMachineApp::keyPressed(key);
	}
}

void CustomApp::keyReleased(int key){
	StateMachineApp::keyReleased(key);
}

void CustomApp::mouseMoved(int x, int y ){
	StateMachineApp::mouseMoved(x, y);
}

void CustomApp::mouseDragged(int x, int y, int button){
	StateMachineApp::mouseDragged(x, y, button);
}

void CustomApp::mousePressed(int x, int y, int button){
	StateMachineApp::mousePressed(x, y, button);
}

void CustomApp::mouseReleased(int x, int y, int button){
	StateMachineApp::mouseReleased(x, y, button);
}