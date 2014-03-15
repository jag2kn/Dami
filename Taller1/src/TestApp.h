#pragma once

#define MATRIX_H 7
#define MATRIX_W 5

#include "ofMain.h"

class TestApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();
		~TestApp();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void dynamicMatrixSetup(int w, int h);

	protected:
		int staticMatrix[MATRIX_H][MATRIX_W];
		int **dynamicMatrix;
		
};
