#pragma once

#include "State.h"

#include "Elipse.h"

#include "ofxGui.h"
#include "ofxPanel.h"

class ElipsesConcentricasState : public State {
public:	
	ElipsesConcentricasState(StateMachineApp* app);
	
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
	Elipse							**elipses;
	int cantidadElipses;

	int								direccioncolor;
	float							delta;
	ParametricObject::RenderMode	renderMode;
};
