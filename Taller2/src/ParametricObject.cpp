#include "ParametricObject.h"


ParametricObject::ParametricObject(int w, int h)
{
	this->w=w;
	this->h=h;
	this->generateGrid();
}

ParametricObject::~ParametricObject(void)
{
}

ofPoint ParametricObject::computePosition(ofPoint point){
	ofPoint p;
	p.x=500*point.x;//sin(i/steps*TWO_PI);point.x*2;
	p.y=500*point.y;//cos(i/steps*TWO_PI);
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


	//ofLogError() << "Draw en ParametricObject";
	//ofBackground(122,122,122);
	ofPushMatrix();
	ofTranslate(100, 100, 0);
	//ofRotate(ang, 1.0, 1.0, 1.0);
	//Now it’s time to draw the mesh. The ofMesh has three drawing methods: drawFaces(),
	//which draws all the faces of the mesh filled; drawWireframe(), which draws lines
	//along each triangle; and drawVertices(), which draws a point at each vertex.
	//Since we want to see the colors we’re drawing, we’ll draw all the faces:
   // camera.begin();
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

    //top & bottom
    //for (int j=0; j<2; j++) {
    //    for (float i=0; i<steps; i++) {
	ofColor c;
	for (j=0;j<1;j+=step_h){
		for (i=0;i<1;i+=step_w){
			c.b=i*255;
			c.g=j*255;
			c.r=255;
			mesh.addColor(c);
			mesh.addVertex(computePosition(ofPoint(i, j, 0)));
			//ofVec3f(xx,yy,zz));
			ofLogNotice()<<xx<<","<<yy<<","<<zz;
        }
    }
	for (j=0;j<h-1;j++){
		for (i=0;i<w-1;i++){
			xx = j*w+i;
			yy = (j+1)*w+i;
			zz = (j+1)*w+i+1;
			mesh.addTriangle(xx,yy,zz);
			ofLogNotice()<<xx<<","<<yy<<","<<zz;
			xx = j*w+i;
			yy = j*w+i+1;
			zz = (j+1)*w+i+1;
			mesh.addTriangle(xx,yy,zz);
			ofLogNotice()<<xx<<","<<yy<<","<<zz;
		}
    }
/*
	mesh.addNormal( ofVec3f( normals[id].x, normals[id].y, normals[id].z ));
	mesh.addIndex(indices[id]);
*/
}
