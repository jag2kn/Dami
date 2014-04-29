#pragma once

#include "State.h"

#include "Torus.h"

#include "ofxGui.h"
#include "ofxPanel.h"

class TransformationsState : public State {
public:	
	TransformationsState(StateMachineApp* app);
	
	void setup();
	void update();
	void draw();

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


	ofxPanel						gui;
	ofxFloatColorSlider				ambient, diffuse, specular;
	ofxIntSlider					hCells, vCells;		
	ofxFloatSlider					R, r, shininess;

	bool							drawGui;

	Torus							*torus;

	float							xRot, yRot;
	ParametricObject::RenderMode	renderMode;

	long							lastTimeSample;

	float							rot, secondRot;
};