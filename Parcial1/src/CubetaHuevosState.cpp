#include "CubetaHuevosState.h"

CubetaHuevosState::CubetaHuevosState(StateMachineApp* app) : State(app){	
}

void CubetaHuevosState::setup(){
	
}

void CubetaHuevosState::update(){
	delta = (ofGetElapsedTimeMillis()%1000)/1000.0;
}

void CubetaHuevosState::draw(){
	ofBackgroundGradient(ofColor(64), ofColor(0), OF_GRADIENT_BAR);
	
	

	glEnable(GL_DEPTH_TEST);

	GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat position[] = {(float)ofGetWidth(), (float)ofGetHeight(), 0.0, 1.0};

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


	vector<ofPoint>		points ;
	points.clear();
	
	points.push_back(ofPoint(500,500,5));
	points.push_back(ofPoint(200,200,5));
	points.push_back(ofPoint(400,100,5));
	

	float shininess=10;


	ofPoint p;

	glBegin(GL_POINTS);
	
		for (int j;j<10;j++){
			for (int i;i<10;i++){
				glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
				glMaterialf(GL_FRONT, GL_SHININESS, shininess);
				glPointSize(50);
	
				p.x=100+i*30;
				p.y=100+i*30;
				p.z=sin(TWO_PI*((float)p.x/10));
	
				glVertex3fv(&p.x);
			
			}
		}
	glEnd();
	
	//camara.end();


	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

}

string CubetaHuevosState::getStateName(){
	return "CubetaHuevosState";
}

void CubetaHuevosState::keyPressed(int key){
}

void CubetaHuevosState::keyReleased(int key){


}

void CubetaHuevosState::mouseMoved(int x, int y ){
}

void CubetaHuevosState::mousePressed(int x, int y, int button){
}

void CubetaHuevosState::mouseReleased(int x, int y, int button){
}

void CubetaHuevosState::mouseDragged(int x, int y, int button){
}

void CubetaHuevosState::in(){
}

void CubetaHuevosState::out(){
}

void CubetaHuevosState::exit(){
	delete torus;
}
