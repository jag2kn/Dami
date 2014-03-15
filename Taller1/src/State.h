#pragma once
#include "StateMachineApp.h"

#ifndef __STATE__
#define __STATE__
	class StateMachineApp;

	class State
	{
		public:
			State(StateMachineApp* app);
			~State(void);
			virtual void setup();
			virtual void update();
			virtual void draw();
			virtual void exit();
			virtual void keyPressed(int key);
			virtual void keyReleased(int key);
			virtual void mouseMoved(int x, int y);
			virtual void mouseDragged(int x, int y, int button);
			virtual void mousePressed(int x, int y, int button);
			virtual void mouseReleased(int x, int y, int button);

		protected:
			char* getStateName(int id);
			void in();
			void out();
			StateMachineApp* app;

		

	};

#endif
