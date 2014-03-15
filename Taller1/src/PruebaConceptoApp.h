#pragma once
#include "StateMachineApp.h"

#define STATE_AZUL  0
#define STATE_ROJO  1
#define STATE_VERDE 2
#define KEY_N 110
#define BOTON_IZQUIERDO 0
#define BOTON_DERECHO 2

class PruebaConceptoApp : public StateMachineApp
{
	public:
		PruebaConceptoApp(void);
		~PruebaConceptoApp(void);
		void setup();
		void draw();
		void update();
		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		bool isTransitionValid(State* from, State* to);
};

