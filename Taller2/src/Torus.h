#pragma once

#include "ofMain.h"
#include "ParametricObject.h"

 

class Torus:public ParametricObject
{
public:
	Torus(int w, int h, float R, float r);
	Torus(int w, int h);

	ofPoint computePosition(ofPoint point);
	ofPoint computeNormal(ofPoint point);
private:
	float R;
	float r;
};

