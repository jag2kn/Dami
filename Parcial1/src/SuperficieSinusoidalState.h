#pragma once

#include "State.h"

#include "Sinusoidal.h"

#include "ofxGui.h"
#include "ofxPanel.h"

class SuperficieSinusoidalState : public State {
public:	
	SuperficieSinusoidalState(StateMachineApp* app);
	
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);

	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseDragged(int x, int y, int button);
		
protected:
	string getStateName();
	void in();
	void out();
	
	ofEasyCam camara;
	Sinusoidal						*sinusoidal;
	
	ofxPanel						gui;
	ofxFloatColorSlider				ambient, diffuse, specular;
	ofxIntSlider					hCells, vCells, a, p;		
	ofxFloatSlider					shininess;

	bool							drawGui;

	int								lasta, lastp;
	float							lastHCells, lastVCells, lastDelta, delta;

	float							xRot, yRot;
	ParametricObject::RenderMode	renderMode;
};
