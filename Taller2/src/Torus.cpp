#include "Torus.h"


Torus::Torus(int w, int h, float R, float r):ParametricObject(w,h)
{
	this->R=R;
	this->r=r;
}

ofPoint Torus::computePosition(ofPoint point){
	ofPoint p;
	float theta = point.x*TWO_PI;
	float phi = point.y*TWO_PI;
	p.x=cos(theta)*(R+r*cos(phi));
	p.y=sin(theta)*(R+cos(phi));
	p.z=r*sin(phi);
	return p;
}

ofPoint Torus::computeNormal(ofPoint point){
	ofPoint p;
	float theta = point.x*TWO_PI;
	float phi = point.y*TWO_PI;
	p.x = (R+r*cos(phi))*cos(theta)-(R+r*cos(phi))*cos(theta);
	p.y = (R+r*cos(phi))*sin(theta)-(R+r*cos(phi))*sin(theta);
	p.z = (r*sin(phi)-r*sin(phi));

	return p;
}

