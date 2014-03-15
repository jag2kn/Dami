#pragma once

#include "ofMain.h"
#include "Generales.h"

 
const int X = 158;
const int Z = 256;
 
//This is the data for the vertices, which keeps the data as simple as possible:
static GLfloat vdata[12][3] = {
{-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
{0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
{Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0} };
 
//data for the indices, representing the index of the vertices
//that are to be connected into the triangle.
//You’ll notice that for 12 vertices you need 20 indices of 3 vertices each:
static GLint indices2[20][3] = {
{0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1}, {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3}, {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6}, {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11}
};

class ParametricObject
{
public:
	ParametricObject(int w, int h);
	~ParametricObject(void);
	
	float ang;
	ofMesh mesh;
	
    float step,steps;
    ofEasyCam camera;

	ofPoint computePosition(ofPoint point);
	ofPoint computeNormal(ofPoint point);
	void draw(
			ofPoint position, 
			ofFloatColor ambientColor,
			ofFloatColor diffuseColor, 
			ofFloatColor specularColor, 
			float shininess, 
			RenderMode renderMode);
private:
	void generateGrid();


protected:
	vector<int> indices;
	vector<ofPoint> points;
	vector<ofPoint> normals;
	int w;
	int h;
};

