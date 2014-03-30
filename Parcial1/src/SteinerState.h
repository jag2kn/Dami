#pragma once

#include "State.h"

#include "Steiner.h"

#include "ofxGui.h"
#include "ofxPanel.h"

class SteinerState : public State {
public:	
	SteinerState(StateMachineApp* app);
	
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
	
	Steiner							*steiner;
	ofxPanel						gui;
	ofxFloatColorSlider				ambient, diffuse, specular;
	ofxIntSlider					hCells, vCells;		
	ofxFloatSlider					r, shininess;

	bool							drawGui;


	float							lastr, lastHCells, lastVCells;

	float							xRot, yRot;
	ParametricObject::RenderMode	renderMode;

};
