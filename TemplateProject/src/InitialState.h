#pragma once

#include "State.h"

class InitialState : public State {
public:	
	InitialState(StateMachineApp* app);
	
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	void mousePressed(int x, int y, int button);
		
protected:
	string getStateName();
	void in();
	void out();	
};