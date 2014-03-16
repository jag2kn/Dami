#include "ToroState.h"

ToroState::ToroState(StateMachineApp* app) : State(app){	
}

ToroState::~ToroState(){
}

void ToroState::setup(){
	ofLogError() << "In en ToroState";
	//obj = new ParametricObject(100, 100);
	obj = new Torus(100, 100, 500, 100);
	obj->generateGrid();
}

void ToroState::update(){
}

void ToroState::draw(){
	//ofLogError() << "Draw en ToroState";

	ofPoint position; 
	ofFloatColor ambientColor;
	ofFloatColor diffuseColor; 
	ofFloatColor specularColor;
	float shininess;
	RenderMode renderMode;

	position.x=200;
	position.y=200;
	ambientColor.r=0.5;
	ambientColor.g=0.5;
	ambientColor.b=0;
	ambientColor.a=0.5;

	diffuseColor.r=0;
	diffuseColor.g=0.5;
	diffuseColor.b=0;
	diffuseColor.a=0.5;

	specularColor.r=0;
	specularColor.g=0.5;
	specularColor.b=.50;
	specularColor.a=1;

	shininess=0.5;

	renderMode = SOLID;

	//ofBackgroundGradient(ofColor(128), ofColor(0), OF_GRADIENT_CIRCULAR);
	obj->draw(position, ambientColor, diffuseColor, specularColor, shininess, renderMode);
	//ofDrawBitmapString(getStateName(), 100, 100);
	//ofDrawBitmapString("asdfasdf", 120, 120);
}

string ToroState::getStateName(){
	return "ToroState";
}

void ToroState::keyPressed(int key){
}

void ToroState::keyReleased(int key){
}

void ToroState::mouseMoved(int x, int y ){
}

void ToroState::mousePressed(int x, int y, int button){
}

void ToroState::mouseReleased(int x, int y, int button){
}

void ToroState::in(){
}

void ToroState::out(){
}

void ToroState::exit(){
	delete obj;

}