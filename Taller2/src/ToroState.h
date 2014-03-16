#pragma once

#include "State.h"
#include "Torus.h"

class ToroState : public State {
public:	
	ToroState(StateMachineApp* app);
	~ToroState();
	
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);

	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	void mousePressed(int x, int y, int button);

	Torus *obj;
protected:
	string getStateName();
	void in();
	void out();	
};