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
	p.x=100*point.x;
	p.y=100*point.y;
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
	//ofSphere(0,0,0, 80);
	int id;

	
	ofLight luz1;
	luz1.enable();
	luz1.setDiffuseColor(diffuseColor);
	luz1.setDirectional();
	luz1.draw();
	glBegin(GL_TRIANGLES);

	aa=1;

	//glBegin(GL_LINES);
	//glEnable(GL_POINT_SMOOTH);
	//glBegin(GL_POINTS);
		int contador=0;
		//indices.size()

		if (aa==0){
			ofLogNotice()<<"Indices: "<<indices.size();
		}
		
		//for(int i=0;i<3;i++){
		for(int i=0;i<indices.size();i+=3){
			
			if (aa==0){
				//ofLogNotice()<<contador%3;
			}
				id_uno = indices[i];
				id_dos = indices[i+1];
				id_tres = indices[i+2];

				
				if (aa==0){
					ofLogNotice() <<"Punto:  "<<ofToString(id_uno)<<", "<<ofToString(id_dos)<<", "<<ofToString(id_tres);
					ofLogNotice() <<"El largo de points es "<<points.at(id_uno);
				}

				p_uno=points[id_uno];
				p_dos=points[id_dos];
				p_tres=points[id_tres];

				n_uno=normals[id_uno];
				n_dos=normals[id_dos];
				n_tres=normals[id_tres];
				
				if (aa==0){
					ofLogNotice() <<"Punto:  "<<ofToString(id_uno)<<", "<<ofToString(id_dos)<<", "<<ofToString(id_tres);
					ofLogNotice() <<"Punto:  "<<ofToString(p_uno)<<", "<<ofToString(p_dos)<<", "<<ofToString(p_tres);
				}

				/*
				ofSphere(p_uno.x, p_uno.y, p_uno.z, 2);
				ofSphere(p_dos.x, p_dos.y, p_dos.z, 2);
				ofSphere(p_tres.x, p_tres.y, p_tres.z, 2);
				*/


				glNormal3f(n_uno.x, n_uno.y, n_uno.z);
				glVertex3f(p_uno.x, p_uno.y, p_uno.z);

				glNormal3f(n_dos.x, n_dos.y, n_dos.z);
				glVertex3f(p_dos.x, p_dos.y, p_dos.z);

				glNormal3f(n_tres.x, n_tres.y, n_tres.z);
				glVertex3f(p_tres.x, p_tres.y, p_tres.z);
		}
	aa = 1;
    glEnd();
	/*mesh.enableColors();
	mesh.drawWireframe();
	mesh.drawFaces();
	*/
    //ofSphere(100,0,0, 80);

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

	int contador=0;
	int contadorIndices=0;
	std::vector<ofPoint>::iterator it_p;
	std::vector<ofPoint>::iterator it_n;
	std::vector<int>::iterator it_i;

	it_p = points.begin();
	it_n = normals.begin();
	it_i = indices.begin();
	float i_sub, j_sub;

	for (j=0;j<h;j++){
		for (i=0;i<w;i++){
			i_sub = i/(w-1);
			j_sub = j/(h-1);
			it_p = points.insert(it_p, computePosition(ofPoint(i_sub, j_sub, 0)));
			it_n = normals.insert(it_n, computePosition(ofPoint(i_sub, j_sub, 0)));
			contador++;

			//ofLogNotice()<<"Punto: "<<i<<" "<<j<<" "<<0<<" -> "<<computePosition(ofPoint(i_sub, j_sub, 0));

		}
	}
	for (j=0;j<h-1;j++){
		for (i=0;i<w-1;i++){

			xx = j*w+i;
			yy = (j+1)*w+i;
			zz = (j+1)*w+(i+1);
			//mesh.addTriangle(xx,yy,zz);
			it_i = indices.insert(it_i, xx);
			it_i = indices.insert(it_i, yy);
			it_i = indices.insert(it_i, zz);
			//ofLogNotice()<<"Agregando: "<<xx<<" "<<yy<<" "<<zz;

			xx = j*w+i;
			yy = j*w+(i+1);
			zz = (j+1)*w+(i+1);
			//mesh.addTriangle(xx,yy,zz);
			it_i = indices.insert(it_i, xx);
			it_i = indices.insert(it_i, yy);
			it_i = indices.insert(it_i, zz);
			//ofLogNotice()<<"Agregando: "<<xx<<" "<<yy<<" "<<zz;

			//mesh.addVertex(computePosition(ofPoint(i, j, 0)));
			//mesh.addNormal(computeNormal(ofPoint(i, j, 0)));
        }
    }
	/*
	ofLogNotice()<<"La cantidad de puntos es: "<<points.size();
	for(int i=0;i<points.size();i++){
		ofLogNotice()<<"Los puntos son: "<<ofToString(points.at(i));
	}*/
	
	
	/*
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
    }*/
	
	/*
	ofLogNotice()<<"Laterales";
	for (j=0;j<h-1;j++){
			xx = j*w;
			yy = (j+1)*w;
			zz = (j+1)*w-1;
			//ofLogNotice() <<xx<<","<<yy<<","<<zz;
			//mesh.addTriangle(xx,yy,zz);
			it_i = indices.insert(it_i, xx);
			it_i = indices.insert(it_i, yy);
			it_i = indices.insert(it_i, zz);
			ofLogNotice()<<"Agregando borde: "<<xx<<" "<<yy<<" "<<zz;
			xx = (j+1)*w;
			yy = (j+1)*w-1;
			zz = (j+2)*w-1;
			//mesh.addTriangle(xx,yy,zz);
			it_i = indices.insert(it_i, xx);
			it_i = indices.insert(it_i, yy);
			it_i = indices.insert(it_i, zz);
			ofLogNotice()<<"Agregando borde: "<<xx<<" "<<yy<<" "<<zz;
			//ofLogNotice() <<xx<<","<<yy<<","<<zz;
	}
	ofLogNotice()<<"Superior";
	for (i=0;i<w-1;i++){
			xx = i;
			yy = i+1;
			zz = i+w*(h-1);
			//mesh.addTriangle(xx,yy,zz);
			it_i = indices.insert(it_i, xx);
			it_i = indices.insert(it_i, yy);
			it_i = indices.insert(it_i, zz);
			ofLogNotice()<<"Agregando borde: "<<xx<<" "<<yy<<" "<<zz;
			xx = (i+1)+w*(h-1);
			yy = i+1;
			zz = i+w*(h-1);
			//mesh.addTriangle(xx,yy,zz);
			it_i = indices.insert(it_i, xx);
			it_i = indices.insert(it_i, yy);
			it_i = indices.insert(it_i, zz);
			ofLogNotice()<<"Agregando borde: "<<xx<<" "<<yy<<" "<<zz;
			//ofLogNotice() <<xx<<","<<yy<<","<<zz;
	}*/

	/*
	ofLogNotice()<<"+++++++++++++"<<indices.size();
	
	int iiii=0;
	for (it_i=indices.begin(); it_i<indices.end(); it_i++){
		xx = *it_i;
		ofLogNotice()<<xx;
		if (iiii%3==2){
			ofLogNotice()<<"-----------";
		}
		iiii++;
	}
	*/

	/*
	mesh.addNormal( ofVec3f( normals[id].x, normals[id].y, normals[id].z ));
	mesh.addIndex(indices[id]);
*/
}
