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
	p.y=sin(theta)*(R+r*cos(phi));
	p.z=r*sin(phi);
	return p;
}

ofPoint Torus::computeNormal(ofPoint point){
	float x = point.x*TWO_PI;
	float y= point.y*TWO_PI;
	ofPoint dT=ofPoint();

	dT.x = (R + r*cos(y))*(-1)*sin(x);
	dT.y = (R + r*cos(y))*(-1)*sin(x);
	dT.z = 0;

	ofPoint dF=ofPoint();
	dF.x = -1*(r*cos(x)*sin(y));
	dF.y = -1*(r*sin(x)*sin(y));
	dF.z = r*cos(y);

	return (dT.cross(dF)).getNormalized();

}

