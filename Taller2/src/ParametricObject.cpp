#include "ParametricObject.h"


ParametricObject::ParametricObject(int w, int h)
{
	this->w=w;
	this->h=h;
}

ParametricObject::~ParametricObject(void)
{
}

ofPoint ParametricObject::computePosition(ofPoint point){
	ofPoint p;
	//p.x=500*point.x;
	//p.y=500*point.y;
	p.x=300*sin(point.x*TWO_PI);
	p.y=300*cos(point.y*TWO_PI);
	p.z=0;
	return p;
}

ofPoint ParametricObject::computeNormal(ofPoint point){
	ofPoint p;
	p.x=0;
	p.y=0;
	p.z=1;
	return p;
}

void ParametricObject::draw(
		ofPoint position, 
		ofFloatColor ambientColor,
		ofFloatColor diffuseColor, 
		ofFloatColor specularColor, 
		float shininess, 
		RenderMode renderMode){

	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
	ofLight luz;
	luz.enable();
	luz.setAmbientColor(ambientColor);
	luz.setDiffuseColor(diffuseColor);
	luz.setSpecularColor(specularColor);
	luz.enable();
	luz.draw();
	


	//ofRotate(ang, 1.0, 1.0, 1.0);
	//Now it’s time to draw the mesh. The ofMesh has three drawing methods: drawFaces(),
	//which draws all the faces of the mesh filled; drawWireframe(), which draws lines
	//along each triangle; and drawVertices(), which draws a point at each vertex.
	//Since we want to see the colors we’re drawing, we’ll draw all the faces:
    camara.begin();
	mesh.drawFaces();
	
	ofPopMatrix(); 

}

void ParametricObject::generateGrid(){
	ofBackground(0);
    glEnable(GL_DEPTH_TEST);
    float steps_w = w;
    float steps_h = h;
    float step_w = 1.0/steps_w;
    float step_h = 1.0/steps_h;

	float xx,yy,zz;
	float i,j;

	for (j=0;j<1;j+=step_h){
		for (i=0;i<1;i+=step_w){
			mesh.addVertex(computePosition(ofPoint(i, j, 0)));
			mesh.addNormal(computeNormal(ofPoint(i, j, 0)));
        }
    }
	for (j=0;j<h-1;j++){
		for (i=0;i<w-1;i++){
			xx = j*w+i;
			yy = (j+1)*w+i;
			zz = (j+1)*w+i+1;
			mesh.addTriangle(xx,yy,zz);
			xx = j*w+i;
			yy = j*w+i+1;
			zz = (j+1)*w+i+1;
			mesh.addTriangle(xx,yy,zz);
		}
    }
/*
	mesh.addNormal( ofVec3f( normals[id].x, normals[id].y, normals[id].z ));
	mesh.addIndex(indices[id]);
*/
}
