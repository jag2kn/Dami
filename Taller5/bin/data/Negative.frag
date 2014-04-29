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
	vec4 color = texture2DRect(tex,gl_FragCoord.xy);	
	int i;
	int j;
	vec4 colorNuevo=texture2DRect(tex,gl_FragCoord.xy);
	for (j=-delta;j<delta;j++){
		for (i=-delta;i<delta;i++){
			//if (gl_FragCoord.x+j>0 && gl_FragCoord.y+i>0){
				colorNuevo += texture2DRect(tex,gl_FragCoord.xy+vec2(j,i));	
			//}
		}
	}
	colorNuevo = colorNuevo/((2*delta+1)*(2*delta+1));
	
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