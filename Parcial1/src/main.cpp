#include "ofMain.h"
#include "CustomApp.h"

int main(){
	ofSetupOpenGL(1024, 768, OF_WINDOW);
	ofRunApp(new CustomApp());
	return 0;
}
