#version 120
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect tex;
uniform vec2 size; 
uniform int delta; 
uniform int invertirR;
uniform int invertirG;
uniform int invertirB;


void main(void)
{
	vec4 colorNuevo;	
	vec4 colorIzquierda=texture2DRect(tex,vec2(gl_FragCoord.x-1,gl_FragCoord.y));
	vec4 colorDerecha=texture2DRect(tex,vec2(gl_FragCoord.x+1,gl_FragCoord.y));

	float promedioIzquierda = (colorIzquierda.x+colorIzquierda.y+colorIzquierda.z)/3;
	float promedioDerecha = (colorDerecha.x+colorDerecha.y+colorDerecha.z)/3;
	
	if (promedioIzquierda-promedioDerecha>0.01){
		colorNuevo = vec4(0,0,0,1);
	}else{
		colorNuevo = vec4(1,1,1,1);
	}
	
	float x=colorDerecha.x-colorIzquierda.y;
	if (x>0.05){
		colorNuevo = vec4(0,x,0,1);
	}else{
		colorNuevo = vec4(0,0,0,1);
	}
	
	
	if (invertirR>0){
		colorNuevo.x = 1-colorNuevo.x;
	}
	if (invertirG>0){
		colorNuevo.y = 1-colorNuevo.y;
	}
	if (invertirB>0){
		colorNuevo.z = 1-colorNuevo.z;
	}

	gl_FragColor = vec4(colorNuevo.xyz, 1.0);
	
	
	
}