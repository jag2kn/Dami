#include "State.h"
#include "StateAzul.h"
#include "StateRojo.h"
#include "StateVerde.h"
#include "PruebaConceptoApp.h"

PruebaConceptoApp::PruebaConceptoApp(void)
{
}

PruebaConceptoApp::~PruebaConceptoApp(void)
{
}

void PruebaConceptoApp::setup(){

	states = new State*[3];
		
	states[STATE_AZUL] = new StateAzul(this);
	states[STATE_ROJO] = new StateRojo(this);
	states[STATE_VERDE] = new StateVerde(this);

	currentState = states[STATE_AZUL];
	
	

}

void PruebaConceptoApp::draw(){
	//cout <<"PruebaConceptoApp::draw"<<endl;
	currentState->draw();
}

void PruebaConceptoApp::update(){
	currentState->update();
}

void PruebaConceptoApp::keyPressed(int key){
	cout <<"Key press: "<<key<<endl;
}

void PruebaConceptoApp::keyReleased(int key){
	if (currentState==states[STATE_VERDE]){
		if (key==KEY_N){
			cout <<"Cambiando a estado Azul"<<endl;
			goToState(STATE_AZUL);
		}
	}
	cout <<"Key released: "<<key<<endl;
}

void PruebaConceptoApp::mousePressed(int x, int y, int button){
	cout <<"Mouse press: "<<button<<" ["<<x<<","<<y<<"]"<<endl;
}

void PruebaConceptoApp::mouseReleased(int x, int y, int button){
	cout<<currentState<<"-"<<states[STATE_AZUL]<<endl;
	if (currentState==states[STATE_AZUL]){
		if (button==BOTON_IZQUIERDO){
			cout <<"Cambiando a estado Rojo"<<endl;
			goToState(STATE_ROJO);
		}
	}
	if (currentState==states[STATE_ROJO]){
		if (button==BOTON_DERECHO){
			cout <<"Cambiando a estado Verde"<<endl;
			goToState(STATE_VERDE);
		}
	}
	cout <<"Mouse released: "<<button<<" ["<<x<<","<<y<<"]"<<endl;
}

bool PruebaConceptoApp::isTransitionValid(State* from, State* to){
	if (from==states[STATE_AZUL] && to==states[STATE_ROJO]){
		return TRUE;
	}
	if (from==states[STATE_ROJO] && to==states[STATE_VERDE]){
		return TRUE;
	}
	if (from==states[STATE_VERDE] && to==states[STATE_AZUL]){
		return TRUE;
	}
	return FALSE;

}