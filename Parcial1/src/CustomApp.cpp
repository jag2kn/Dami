#include "CustomApp.h"
#include "InitialState.h"
#include "SteinerState.h"
#include "SuperficieSinusoidalState.h"
#include "ElipsesConcentricasState.h"
#include "CubetaHuevosState.h"
#include "ToroParticulasState.h"

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
		case STEINEN_STATE:
			return new SteinerState(this);
		case SUPERFICIE_SINUSOIDAL_STATE:
			return new SuperficieSinusoidalState(this);
		case ELIPSES_COCENTRICAS_STATE:
			return new ElipsesConcentricasState(this);
		case CUBETA_HUEVOS_STATE:
			return new CubetaHuevosState(this);
		case TORO_PARTICULAS_STATE: 
			return new ToroParticulasState(this);
	}
	
	return NULL;
}

string CustomApp::getStateName(int id){
	return "";
}

bool CustomApp::isTransitionValid(State* from, State* to){
	return true;
}

void CustomApp::keyPressed(int key){
	switch(key){
	case '0':
		goToState(STEINEN_STATE);
		break;
	case '1':
		goToState(SUPERFICIE_SINUSOIDAL_STATE);
		break;
	case '2':
		goToState(ELIPSES_COCENTRICAS_STATE);
		break;
	case '3':
		goToState(CUBETA_HUEVOS_STATE);
		break;
	case '4':
		goToState(TORO_PARTICULAS_STATE);
		break;
	default:
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
