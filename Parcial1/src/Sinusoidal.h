#pragma once

#include "ParametricObject.h"

class Sinusoidal : public ParametricObject {
public:
	Sinusoidal(int w, int h, int a, int p);
	~Sinusoidal(void);

	ofPoint computePosition(ofPoint point);
	ofPoint computeNormal(ofPoint point);

protected:
	float getBigR(float phi, float theta, float periods = 1, float waveMagnitude = 0, float phase = 0);
	float getSmallR(float phi, float theta, float periods = 1, float waveMagnitude = 0, float phase = 0);

	float a, p;
};

