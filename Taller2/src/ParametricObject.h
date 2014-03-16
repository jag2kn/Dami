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
	void setup();


	void generateGrid();
private:
	void setLightOri(ofLight &light, ofVec3f rot);
	ofLight spot;
    ofLight point;
    ofLight dir;
    ofLight amb;
    ofMaterial material;
	ofVec3f dir_rot;
    ofVec3f spot_rot;
	int aa;


protected:
	vector<int> indices;
	vector<ofPoint> points;
	vector<ofPoint> normals;
	int w;
	int h;
};

