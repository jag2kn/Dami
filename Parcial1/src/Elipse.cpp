#include "Elipse.h"

Elipse::Elipse(int w, int h, int R, int r) : ParametricObject(w, h) {
	this->R = R;
	this->r = r;
}


Elipse::~Elipse(void){
}

ofPoint Elipse::computePosition(ofPoint point){
	int x = point.x*R*cos(point.y);
	int y = point.x*r*sin(point.y);

	return ofPoint(x, y, 0);

}

ofPoint Elipse::computeNormal(ofPoint point){
	
	ofPoint normal;
	normal.x = 0;
	normal.y = 0;
	normal.z = 1;
	return normal;
}

float Elipse::getBigR(float phi, float theta, float periods, float waveMagnitude, float phase) {
	return R + waveMagnitude * sin(periods * phi + phase);
}

float Elipse::getSmallR(float phi, float theta, float periods, float waveMagnitude, float phase) {
	return r + waveMagnitude * sin(periods * theta + phase);
}
