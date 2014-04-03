#include "SuperficieSinusoidalState.h"

SuperficieSinusoidalState::SuperficieSinusoidalState(StateMachineApp* app) : State(app){	
}

void SuperficieSinusoidalState::setup(){
	gui.setup();
	gui.add(ambient.setup("Ambient", ofColor(0), ofColor(0), ofColor(255)));
	gui.add(diffuse.setup("Diffuse", ofColor(255), ofColor(0), ofColor(255)));
	gui.add(specular.setup("Specular", ofColor(255), ofColor(0), ofColor(255)));
	gui.add(shininess.setup("Shininess", 128, 0.1, 128));	
	gui.add(hCells.setup("rows", 50, 4, 100));
	gui.add(vCells.setup("cols", 50, 4, 100));
	gui.add(a.setup("Amplitud", 25, 20, 100));
	gui.add(p.setup("Periodos", 3, 1, 20));

	drawGui = true;



	sinusoidal = new Sinusoidal(20, 20, 25, 3, 0);
	
	lasta = a;
	lastp = p;
	lastDelta = 0;
	lastHCells = hCells;
	lastVCells = vCells;

	xRot = yRot = 0;


	renderMode = ParametricObject::WIREFRAME;
}

void SuperficieSinusoidalState::update(){
	delta = (float)(ofGetElapsedTimeMillis()%1000)/1000;
	//ofLogNotice()<<"Delta update :"<<delta<<" - "<<ofGetElapsedTimeMillis();
}

void SuperficieSinusoidalState::draw(){

	
	ofBackgroundGradient(ofColor(64), ofColor(0), OF_GRADIENT_BAR);
	
	//ofLog()<<"Delta draw: "<<delta;
	if(lasta != a || lastp != p || lastHCells != hCells || lastVCells != vCells || lastDelta !=delta){
		delete sinusoidal;
		sinusoidal = new Sinusoidal(hCells, vCells, a, p, delta);
	}
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
	
	//ofEnableBlendMode(OF_BLENDMODE_ADD);

	
	glPushMatrix();
	glTranslatef(0, 0, -400);
	glTranslatef(ofGetWidth() / 2, ofGetHeight() / 2, 0.0);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glTranslatef(-ofGetWidth() / 2, -ofGetHeight() / 2, 0.0);
	glTranslatef(-1000, -1000, 0.0);
	if(sinusoidal)
		sinusoidal->draw(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, -100), 
		this->ambient,
		this->diffuse, 
		this->specular, 
		shininess, 
		renderMode);
	glPopMatrix();
	
	//camara.end();


	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	if(drawGui)
		gui.draw();


	lasta = a;
	lastp = p;
	lastDelta = delta;
	lastHCells = hCells;
	lastVCells = vCells;

}

string SuperficieSinusoidalState::getStateName(){
	return "SuperficieSinusoidalState";
}

void SuperficieSinusoidalState::keyPressed(int key){
}

void SuperficieSinusoidalState::keyReleased(int key){


	if(key == 'l' || key == 'L')
		renderMode = ParametricObject::WIREFRAME;

	if(key == 's')
		renderMode = ParametricObject::SOLID;

	if(key == 'p')
		renderMode = ParametricObject::POINTS;
}

void SuperficieSinusoidalState::mouseMoved(int x, int y ){
}

void SuperficieSinusoidalState::mousePressed(int x, int y, int button){
	xRot = y / (float)ofGetHeight() * 360;
	yRot = x / (float)ofGetWidth() * 360;
}

void SuperficieSinusoidalState::mouseReleased(int x, int y, int button){
}

void SuperficieSinusoidalState::mouseDragged(int x, int y, int button){
	xRot = y / (float)ofGetHeight() * 360;
	yRot = x / (float)ofGetWidth() * 360;
}

void SuperficieSinusoidalState::in(){
}

void SuperficieSinusoidalState::out(){
}

void SuperficieSinusoidalState::exit(){
	delete sinusoidal;
}
