#ifndef PLANE_H
#define PLANE_H

#include "Algebra.h"
#include "Cube.h"

class Plane {
public:
	float x, y, z;

	Plane(float x, float y, float z) {
		x = x;
		y = y;
		z = z;
	}

	void draw() {
		glPushMatrix();
		glScalef(x, y, z);
		glutSolidCube(10.0);
		glPopMatrix();
	}
};


#endif
