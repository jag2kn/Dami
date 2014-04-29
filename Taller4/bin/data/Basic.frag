#version 120 

uniform vec2 size;
uniform vec2 center; 
uniform float radius;
uniform vec3 lightPosition; 

varying vec3 normal; 

void main(void) 
{
/*
	float x = gl_FragCoord.y; 
	float y = size.y - gl_FragCoord.y; 
	float distance = distance(gl_FragCoord.xy, vec2(center.x, size.y - center.y));
	if(distance < radius){
	} else { 
		discard; 
	} */
	float x = gl_FragCoord.y; 
	float y = size.y - gl_FragCoord.y; 

	vec3 L = vec3(lightPosition.x, size.y - lightPosition.y, lightPosition.z); 
	vec3 lightDirection = normalize(L - gl_FragCoord.xyz); 

	float angle = dot(normal, lightDirection); 

	gl_FragColor = vec4(gl_FrontMaterial.diffuse.xyz * angle, 1.0); 
} 