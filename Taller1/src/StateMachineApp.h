#pragma once

#define MATRIX_H 7
#define MATRIX_W 5

#include "ofMain.h"
#include "State.h"

#ifndef __STATEMACHINE__
#define __STATEMACHINE__

	class State;

	class StateMachineApp : public ofBaseApp{

		public:
			~StateMachineApp();
			void goToState(int id);

		//protected:
			State *currentState;
			//std::vector<State*> states;
			State** states;

			virtual void setup();
			virtual void update();
			virtual void draw();
			virtual void exit();
			void setupInternal();
			void updateInternal();
			void drawInternal();
			void exitInternal();

			virtual void keyPressed(int key);
			virtual void keyReleased(int key);
			virtual void mouseMoved(int x, int y );
			virtual void mouseDragged(int x, int y, int button);
			virtual void mousePressed(int x, int y, int button);
			virtual void mouseReleased(int x, int y, int button);

			int getStateCount();
			State* createState(int id);
			char* getStateName (int id);
			bool isTransitionValid(State* from, State* to);
		
	};

#endif
