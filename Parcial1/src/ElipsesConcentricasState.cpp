#include "ElipsesConcentricasState.h"

ElipsesConcentricasState::ElipsesConcentricasState(StateMachineApp* app) : State(app){	
}

void ElipsesConcentricasState::setup(){
	
	delta = 0;
	direccioncolor = 1;
	renderMode = ParametricObject::SOLID;
}

void ElipsesConcentricasState::update(){
	delta = (ofGetElapsedTimeMillis()%1000)/1000.0;
}

void ElipsesConcentricasState::draw(){
	ofBackgroundGradient(ofColor(64), ofColor(0), OF_GRADIENT_BAR);
	
	

	glEnable(GL_DEPTH_TEST);

	GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat position[] = {ofGetWidth(), ofGetHeight(), 0, 1.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	/*
	if (delta==0){
		direccioncolor*=-1;
	}*/

	ofFloatColor amb, dif, spe;
	float shi;
	amb.r=0.0;
	amb.g=0.0;
	amb.b=0.0;
	dif.r=1.0*abs(2*(delta-delta/2));
	dif.g=0.0;
	dif.b=1.0;
	spe.r=1;
	spe.g=1;
	spe.b=1;
	shi = 10;

	ofFloatColor amb2, dif2, spe2;
	float shi2;
	amb2.r=0.0;
	amb2.g=0.0;
	amb2.b=0.0;
	dif2.g=0.0;
	dif2.r=1.0*abs(2*(delta-delta/2));
	dif2.b=1.0;
	spe2.r=1;
	spe2.g=1;
	spe2.b=1;
	shi2 = 10;


	float rotacion1 =360.0*delta;
	float rotacion2 =2.0*360.0*delta;
	int n=3, n_i;
	int m=8, m_j;
	float dato_escala;
	float dato_rotacion;
	float angulo_desfase=5;

	
	//camara.end();


	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

}

string ElipsesConcentricasState::getStateName(){
	return "ElipsesConcentricasState";
}

void ElipsesConcentricasState::keyPressed(int key){
}

void ElipsesConcentricasState::keyReleased(int key){


	if(key == 'l' || key == 'L')
		renderMode = ParametricObject::WIREFRAME;

	if(key == 's')
		renderMode = ParametricObject::SOLID;

	if(key == 'p')
		renderMode = ParametricObject::POINTS;
}

void ElipsesConcentricasState::mouseMoved(int x, int y ){
}

void ElipsesConcentricasState::mousePressed(int x, int y, int button){
}

void ElipsesConcentricasState::mouseReleased(int x, int y, int button){
}

void ElipsesConcentricasState::mouseDragged(int x, int y, int button){
}

void ElipsesConcentricasState::in(){
}

void ElipsesConcentricasState::out(){
}

void ElipsesConcentricasState::exit(){
}
