#include "InitialState.h"

InitialState::InitialState(StateMachineApp* app) : State(app){	
}

void InitialState::setup(){
	gui.setup();
	gui.add(useCam.setup("Usar camara", true));
	gui.add(useShader.setup("Usar shader", true));	
	gui.add(delta.setup("delta", 2, 1, 20));
	gui.add(invertirR.setup("R",false));
	gui.add(invertirG.setup("G",false));
	gui.add(invertirB.setup("B",false));
	gui.add(seleccionShader.setup("Shader Negativo/Borde",false));

	shaderNegativo.load("Negative.vert", "Negative.frag");	
	shaderBorde.load("Borde.vert", "Borde.frag");	

	cam.initGrabber(960, 720, true);
	fbo.allocate(cam.getWidth(), cam.getHeight(), GL_RGB);

	//video.loadMovie("video.mov");
	//video.setLoopState(OF_LOOP_NORMAL);
	//video.play();

	drawGui = false;
}

void InitialState::update(){
}

void InitialState::draw(){
	if(useCam) {
		cam.update();
		if(fbo.getWidth() != cam.getWidth() || fbo.getHeight() != cam.getHeight()){
			fbo.allocate(cam.getWidth(), cam.getHeight(), GL_RGB);
		}
	} else {
		video.update();
		if(fbo.getWidth() != video.getWidth() || fbo.getHeight() != video.getHeight()){
			fbo.allocate(video.getWidth(), video.getHeight(), GL_RGB);
		}
	}

	
	ofShader *pShader;
	if (seleccionShader){
		pShader = &shaderNegativo;
	}else{
		pShader = &shaderBorde;
	}
	
	
	if(useShader){
		fbo.begin();	//Habilitar fbo para pintar en él la salida del shader
			pShader->begin();	//Habilitar shader para transformar la textura
				pShader->setUniformTexture("tex", useCam ? cam.getTextureReference() : video.getTextureReference(), 0);	//Pasar como parámetro la textura a transformar			
				pShader->setUniform2f("size", ofGetWidth(), ofGetHeight());
				pShader->setUniform1i("delta", delta);
				pShader->setUniform1i("invertirR", invertirR);
				pShader->setUniform1i("invertirG", invertirG);
				pShader->setUniform1i("invertirB", invertirB);
			
				//Pintar rectángulo que define los fragmentos que serán afectados
				//Se usa el tamaño del FBO
				ofRect(0, 0, fbo.getWidth(), fbo.getHeight());
			pShader->end();
		fbo.end();

		fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	} else {
		//if(useCam)
			cam.draw(0, 0, ofGetWidth(), ofGetHeight());
		/*else
			video.draw(0, 0, ofGetWidth(), ofGetHeight());
			*/
	}

	if(drawGui)
		gui.draw();
}

string InitialState::getStateName(){
	return "InitialState";
}

void InitialState::keyPressed(int key){
}

void InitialState::keyReleased(int key){
	if(key == ' ')
		drawGui = !drawGui;
}

void InitialState::mouseMoved(int x, int y ){
}

void InitialState::mousePressed(int x, int y, int button){
}

void InitialState::mouseReleased(int x, int y, int button){
}

void InitialState::mouseDragged(int x, int y, int button){
}

void InitialState::in(){
}

void InitialState::out(){
}