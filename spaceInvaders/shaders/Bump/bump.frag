/*
Author: Logan Parmeter
*/
//fragment shader, create a file for it named fragment.frag
#version 120

// TODO Step 0: Pass in 3 uniform variables
// Make sure they are named exactly as they are in the cpp file
// images are of type 'uniform sampler2D' and then the texture name.

uniform sampler2D brick_image;
uniform sampler2D bump_image;
uniform vec3 lightVector;

void main()
{
	// TODO Step 1:
	// Extract normals from the normal map
	vec3 normal = normalize(texture2D(bump_image, gl_TexCoord[0].st).rgb * 2.0 - 1.0);

	// TODO Step 2:
	// Multiply lighting times original texture color to figure out how much light we receive
	vec3 light_pos = normalize(vec3(lightVector.x, lightVector.y, lightVector.z));
	float diffuse = max(dot(normal, light_pos), 0.0);

	// TODO Step 3:
	// Find the final color
	vec3 final_color = diffuse * (texture2D(brick_image, gl_TexCoord[0].st).rgb);
	gl_FragColor = vec4(final_color,1.0);

}