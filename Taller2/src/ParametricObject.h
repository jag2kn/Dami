#pragma once

#include "ofMain.h"
#include "Generales.h"


class ParametricObject
{
public:
	ParametricObject(int w, int h);
	~ParametricObject(void);
	
	ofMesh mesh;
	ofEasyCam camara;

	virtual ofPoint computePosition(ofPoint point);
	virtual ofPoint computeNormal(ofPoint point);
	void draw(
			ofPoint position, 
			ofFloatColor ambientColor,
			ofFloatColor diffuseColor, 
			ofFloatColor specularColor, 
			float shininess, 
			RenderMode renderMode);


	void generateGrid();


protected:
	vector<int> indices;
	vector<ofPoint> points;
	vector<ofPoint> normals;
	int w;
	int h;
};

