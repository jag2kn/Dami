#include "ParametricObject.h"


ParametricObject::ParametricObject(int w, int h)
{
	this->w=w;
	this->h=h;
	aa=0;
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
void
ParametricObject::setLightOri(ofLight &light, ofVec3f rot)
{
    ofVec3f xax(1, 0, 0);
    ofVec3f yax(0, 1, 0);
    ofVec3f zax(0, 0, 1);
    ofQuaternion q;
    q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
    light.setOrientation(q);
}

void ParametricObject::setup(){
	ofBackground(0);
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetGlobalAmbientColor(ofColor(0, 0, 0));
    ofSetSmoothLighting(true);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    ofSetSphereResolution(100);
     //sphere radius
    
    spot.setDiffuseColor(ofFloatColor(255.0, 0.0, 0.0f));
    spot.setSpecularColor(ofColor(0, 0, 255));
    spot.setSpotlight();
    spot.setSpotConcentration(5);
    spot.setSpotlightCutOff(10);
    spot_rot = ofVec3f(0, 0, 0);
    setLightOri(spot, spot_rot);

    spot.setPosition(0, 0, 300);
    
    point.setDiffuseColor(ofColor(0.0, 255.0, 0.0));
    
    point.setPointLight();
    
    dir.setDiffuseColor(ofColor(0.0f, 0.0f, 255.0f));
    dir.setSpecularColor(ofColor(255.0f, 0.0f, 0.0f));
    
    dir.setDirectional();
    dir_rot = ofVec3f(0, -95, 0);
    setLightOri(dir, dir_rot);
    
    amb.setAmbientColor(ofColor(20.0, 20.0, 20.0, 20.0));
    
    material.setShininess(120);

    material.setSpecularColor(ofColor(255, 255, 255, 255));
    material.setEmissiveColor(ofColor(0, 0, 0, 255));
    material.setDiffuseColor(ofColor(255, 255, 255, 255));
    material.setAmbientColor(ofColor(255, 255, 255, 255));
    
    
    
}

void ParametricObject::draw(
		ofPoint position, 
		ofFloatColor ambientColor,
		ofFloatColor diffuseColor, 
		ofFloatColor specularColor, 
		float shininess, 
		RenderMode renderMode){

	camara.begin();
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
	
	ofSetLineWidth(5);
    ofSetColor(255, 0, 0);
    ofLine(0, 0, 200, 0);
    ofSetColor(0, 255, 0);
    ofLine(0, 0, 0, 200);
    ofSetColor(0, 0, 255);
    ofLine(0, 0, 0, 0, 0, 200);

	amb.enable();
	dir.enable();
    spot.enable();
    point.enable();
    //glDisable(GL_COLOR_MATERIAL);
    material.begin();    
	
	
	int id_uno, id_dos, id_tres;
	ofPoint p_uno, p_dos, p_tres;
	ofPoint n_uno, n_dos, n_tres;
	ofSphere(0,0,0, 80);
	int id;

	
	ofLight luz1;
	luz1.enable();
	luz1.setDiffuseColor(diffuseColor);
	luz1.setDirectional();
	luz1.draw();
	//glBegin(GL_TRIANGLES);
	glBegin(GL_LINES);
		int contador=0;
		//indices.size()

		if (aa==0){
			ofLogNotice()<<"Indices: "<<indices.size();
		}
		for(int i=0;i<indices.size();i++){
			
			if (aa==0){
				//ofLogNotice()<<contador%3;
			}
			switch(contador%3){
			case 0:
				id_uno = indices.at(contador);
				break;
			case 1:
				id_dos = indices.at(contador);
				break;
			case 2:
				id_tres = indices.at(contador);


				p_uno=points.at(id_uno);
				p_dos=points.at(id_dos);
				p_tres=points.at(id_dos);

				n_uno=normals.at(id_uno);
				n_dos=normals.at(id_dos);
				n_tres=normals.at(id_dos);
				
				if (aa==0){
					//ofLogNotice() <<"Punto:  "<<ofToString(id_uno)<<", "<<ofToString(id_dos)<<", "<<ofToString(id_tres);
				}


				glVertex3f(p_uno.x, p_uno.y, p_uno.z);
				glVertex3f(p_dos.x, p_dos.y, p_dos.z);
				glVertex3f(p_tres.x, p_tres.y, p_tres.z);

				glNormal3f(n_uno.x, n_uno.y, n_uno.z);
				glNormal3f(n_dos.x, n_dos.y, n_dos.z);
				glNormal3f(n_tres.x, n_tres.y, n_tres.z);
				break;
			}
			contador++;			
		}
	aa = 1;
    glEnd();
	/*mesh.enableColors();
	mesh.drawWireframe();
	mesh.drawFaces();
	*/
    ofSphere(100,0,0, 80);

	amb.disable();
    dir.disable();
    spot.disable();
    point.disable();
    material.end();
    ofDisableLighting();


	ofSetColor(spot.getDiffuseColor());
	spot.draw();
	ofSetColor(point.getDiffuseColor());
	point.draw();
	ofSetColor(dir.getDiffuseColor());
	dir.draw();

	
	ofPopMatrix(); 
	camara.end();

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
			points.push_back(computePosition(ofPoint(i, j, 0)));
			normals.push_back(computePosition(ofPoint(i, j, 0)));
			xx = j*w+i;
			yy = (j+1)*w+i;
			zz = (j+1)*w+i+1;
			//mesh.addTriangle(xx,yy,zz);
			indices.push_back(xx);
			indices.push_back(yy);
			indices.push_back(zz);
			xx = j*w+i;
			yy = j*w+i+1;
			zz = (j+1)*w+i+1;
			//mesh.addTriangle(xx,yy,zz);
			indices.push_back(xx);
			indices.push_back(yy);
			indices.push_back(zz);

			//mesh.addVertex(computePosition(ofPoint(i, j, 0)));
			//mesh.addNormal(computeNormal(ofPoint(i, j, 0)));
        }
    }
	for (j=0;j<h-1;j++){
		for (i=0;i<w-1;i++){
			xx = j*w+i;
			yy = (j+1)*w+i;
			zz = (j+1)*w+i+1;
			//mesh.addTriangle(xx,yy,zz);
			indices.push_back(xx);
			indices.push_back(yy);
			indices.push_back(zz);
			xx = j*w+i;
			yy = j*w+i+1;
			zz = (j+1)*w+i+1;
			//mesh.addTriangle(xx,yy,zz);
			indices.push_back(xx);
			indices.push_back(yy);
			indices.push_back(zz);
		}
    }
	for (j=0;j<h-1;j++){
			xx = j*w;
			yy = (j+1)*w;
			zz = (j+1)*w-1;
			ofLogNotice() <<xx<<","<<yy<<","<<zz;
			//mesh.addTriangle(xx,yy,zz);
			indices.push_back(xx);
			indices.push_back(yy);
			indices.push_back(zz);
			xx = (j+1)*w;
			yy = (j+1)*w-1;
			zz = (j+2)*w-1;
			//mesh.addTriangle(xx,yy,zz);
			indices.push_back(xx);
			indices.push_back(yy);
			indices.push_back(zz);
			ofLogNotice() <<xx<<","<<yy<<","<<zz;
	}
	for (i=0;i<w-1;i++){
			xx = i;
			yy = i+1;
			zz = i+w*(h-1);
			ofLogNotice() <<xx<<","<<yy<<","<<zz;
			//mesh.addTriangle(xx,yy,zz);
			indices.push_back(xx);
			indices.push_back(yy);
			indices.push_back(zz);
			xx = i+w*(h-1);
			yy = (i+1)+w*(h-1);
			zz = i+1;
			//mesh.addTriangle(xx,yy,zz);
			indices.push_back(xx);
			indices.push_back(yy);
			indices.push_back(zz);
			ofLogNotice() <<xx<<","<<yy<<","<<zz;
	}

	
	ofLogNotice()<<"+++++++++++++";
	for(int i=0;i<indices.size()/100;i++){
		xx = indices.at(i);
		ofLogNotice()<<xx;
		if (i%3==2){
			ofLogNotice()<<"-----------";
		}
	}


	/*
	mesh.addNormal( ofVec3f( normals[id].x, normals[id].y, normals[id].z ));
	mesh.addIndex(indices[id]);
*/
}
