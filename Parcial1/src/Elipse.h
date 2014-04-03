#pragma once

#include "ParametricObject.h"

class Elipse : public ParametricObject {
public:
	Elipse(int w, int h, int R, int r);
	~Elipse(void);

	ofPoint computePosition(ofPoint point);
	ofPoint computeNormal(ofPoint point);

protected:
	float getBigR(float phi, float theta, float periods = 1, float waveMagnitude = 0, float phase = 0);
	float getSmallR(float phi, float theta, float periods = 1, float waveMagnitude = 0, float phase = 0);

	float R, r;
};

