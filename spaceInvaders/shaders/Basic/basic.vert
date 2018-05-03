#version 120 //Most current OpenGL version avaible in BGE at this shader creation time
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
	TexCoords = aPos;
	gl_Position = projection * view * vec4(aPos, 1.0);
}





