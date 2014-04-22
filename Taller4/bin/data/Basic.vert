#version 120 
#define PI 3.141592654 

uniform vec2 size; 
uniform float amplitude; 
uniform int periods; 
uniform float phase; 

varying vec3 normal; 

void main(void) 
{ 
	//gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; 
	vec4 vertex = gl_Vertex; 
	gl_Position = gl_ModelViewProjectionMatrix * vertex; 

	normal = gl_NormalMatrix * gl_Normal; 

	vertex.z += 10 * sin(vertex.x / 100.0); 
	gl_Position = gl_ModelViewProjectionMatrix * vertex; 
	gl_Position.x += amplitude * sin(gl_Position.x / size.x * periods * 2 * PI + phase); 
	gl_Position.y += amplitude * sin(gl_Position.y / size.y * periods * 2 * PI + phase); 
}