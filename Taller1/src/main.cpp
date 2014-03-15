#include "ofMain.h"
#include "PruebaConceptoApp.h"
#include "StateMachineApp.h"
#include "TestApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(300,300,OF_WINDOW);			// <-------- setup the GL context
	ofSetFrameRate(60);
	ofBackground(0,0,0);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new PruebaConceptoApp());
	//ofRunApp(new StateMachineApp());
	//ofRunApp(new TestApp());

}
