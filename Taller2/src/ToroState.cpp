#include "ToroState.h"

ToroState::ToroState(StateMachineApp* app) : State(app){	
}

ToroState::~ToroState(){
}

void ToroState::setup(){
	ofLogError() << "In en ToroState";
	obj = new ParametricObject(5, 5);
	//obj = new Torus(100, 100, 300, 70);
	obj->generateGrid();
	obj->setup();

	button.setup("Nombre boton");
	button.addListener(this, &ToroState::callback);

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

	button.draw();


	position.x=200;
	position.y=200;
	ambientColor.r=0.0;
	ambientColor.g=0.0;
	ambientColor.b=1.0;
	ambientColor.a=1.0;

	diffuseColor.r=0.0;
	diffuseColor.g=1.0;
	diffuseColor.b=1.0;
	diffuseColor.a=1.0;

	specularColor.r=1.0;
	specularColor.g=0.0;
	specularColor.b=0.0;
	specularColor.a=1.0;

	shininess=0;

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


void ToroState::callback(){
	ofLogNotice() <<"Saludando desde el boton";
}