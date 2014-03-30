#pragma once

#include "State.h"

#include "Torus.h"

#include "ofxGui.h"
#include "ofxPanel.h"

class CubetaHuevosState : public State {
public:	
	CubetaHuevosState(StateMachineApp* app);
	
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
	Torus							*torus;

	int								direccioncolor;
	float							delta;
	ParametricObject::RenderMode	renderMode;
};
