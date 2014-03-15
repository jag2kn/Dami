#include "TestApp.h"

//--------------------------------------------------------------
void TestApp::setup(){

}

//--------------------------------------------------------------
void TestApp::update(){
	//Crear la matriz dinámica con tamaños arbitrarios.
	//Estos datos podrían venir del usuario
	int dynamicW=6,dynamicH=3;
	dynamicMatrixSetup(dynamicW,dynamicH);
	//Llenar matriz dinámica
	for(int row=0;row<dynamicH;row++){
		for(int col=0;col<dynamicW;col++){
			dynamicMatrix[row][col]=ofRandom(100,200);
		}
	}
	//Llenar matriz estática
	for(int row=0;row<MATRIX_H;row++){
		for(int col=0;col<MATRIX_W;col++){
			staticMatrix[row][col]=ofRandom(100,200);
		}
	}
	//Ahora se muestran los datos de cada matrizofLogNotice()<<"Matriz dinamica:";
	for(int row=0;row<dynamicH;row++){
		string s;
		for(int col=0;col<dynamicW;col++){
			s+=ofToString(dynamicMatrix[row][col])+"\t";
		}
		ofLogNotice()<<s;
	}
	
	ofLogNotice()<<"Matriz estatica:";
	for(int row=0;row<MATRIX_H;row++){
		string s;
		for(int col=0;col<MATRIX_W;col++){
			s+=ofToString(staticMatrix[row][col])+"\t";
		}
		ofLogNotice()<<s;
	}

}

//--------------------------------------------------------------
void TestApp::draw(){

}

//--------------------------------------------------------------
void TestApp::keyPressed(int key){

}

//--------------------------------------------------------------
void TestApp::keyReleased(int key){

}

//--------------------------------------------------------------
void TestApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void TestApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void TestApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void TestApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void TestApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void TestApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void TestApp::dragEvent(ofDragInfo dragInfo){ 

}


void TestApp::dynamicMatrixSetup(int w, int h){
	//Asignar memoria para cada fila
	dynamicMatrix = new int*[h];
	//Recorrer cada fila y asignar memoria para las columnas
	for(int row=0;row<h;row++){
		dynamicMatrix[row]=new int[w];
	}
}

void TestApp::exit(){
}

TestApp::~TestApp(){
	//Eliminar memoria asignada para las columnas de cada fila
	for(int row=0;row<3;row++){
		delete[]dynamicMatrix[row];
	}
	//Eliminar memoria asignada para las filas
	delete[]dynamicMatrix;
}



