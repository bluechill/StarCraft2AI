#version 120

varying vec2 texcoord;
	
void main(void) {
	gl_Position = vec4(gl_Vertex.xy, 0, 1);
	texcoord = gl_Vertex.zw;
}
