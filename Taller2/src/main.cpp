#include "ofMain.h"
#include "CustomApp.h"

int main(){
	ofSetupOpenGL(1024, 768, OF_WINDOW);
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofRunApp(new CustomApp());
	return 0;
}
