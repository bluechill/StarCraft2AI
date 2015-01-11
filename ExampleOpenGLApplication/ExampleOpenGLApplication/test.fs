#version 120
	
varying vec2 texcoord;
uniform vec4 color;
uniform sampler2D tex;
	
void main(void) {
	gl_FragColor = vec4(1, 1, 1, texture2D(tex, texcoord).r) * color;
}
