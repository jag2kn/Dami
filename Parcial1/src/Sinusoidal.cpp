#include "Sinusoidal.h"

Sinusoidal::Sinusoidal(int w, int h, int a, int p) : ParametricObject(w, h) {
	this->p = p;
	this->a = a;
}


Sinusoidal::~Sinusoidal(void){
}

ofPoint Sinusoidal::computePosition(ofPoint point){
	
	ofPoint destino;
	
	destino.x = point.x*2000;// * cos(point.y);
	destino.y = point.y*2000;// * sin(point.y);

	//ofLog()<<"["<<<<","<<",]"

	destino.z = sin(p*TWO_PI*sqrt(pow(point.x-0.5,2)+pow(point.y-0.5,2)))*a;


	return destino;
}

ofPoint Sinusoidal::computeNormal(ofPoint point){
	/*
	float phi = point.x * 2.0 * PI, theta = point.y * 2.0 * PI;
	float R = getBigR(phi, theta/*, 6, 100, 0* /), r = getSmallR(phi, theta/*, 10, 20, 0* /);

	ofPoint dTheta = ofPoint(r * sin(theta) * cos(phi),
							 r * cos(theta),
							 r * sin(theta) * sin(phi));

	ofPoint dPhi = ofPoint(-R * sin(phi) + r * cos(theta) * sin(phi),
						   0,
						   R * cos(phi) - r * cos(phi) * cos(theta));

	ofPoint normal = dPhi.getCrossed(dTheta).getNormalized();
	*/
	ofPoint normal ;
	normal.x =0;
	normal.y =-1;
	normal.z =0;

	return normal;
}

float Sinusoidal::getBigR(float phi, float theta, float periods, float waveMagnitude, float phase) {
	return 1;//R + waveMagnitude * sin(periods * phi + phase);
}

float Sinusoidal::getSmallR(float phi, float theta, float periods, float waveMagnitude, float phase) {
	return 1;//r + waveMagnitude * sin(periods * theta + phase);
}