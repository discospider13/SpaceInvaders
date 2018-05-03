#version 120
out vec4 FragColor;

in vec3 TexCoords;

unicorm samplerCube skybox;

void main()
{
	FragColor = texture(skybox, TexCoords);
}






