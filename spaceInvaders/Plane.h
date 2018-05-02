#ifndef PLANE_H
#define PLANE_H

#include "Algebra.h"

class Plane {
private:
	float x, y, z;

public:
	Plane(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void draw() {
		glPushMatrix();
			glTranslatef(0.0, 0.0, 0.0);
			glScalef(this->x, this->y, this->z);
			glColor3f(0.0f, 1.0f, 1.0f);
			glutSolidCube(1.0);
		glPopMatrix();
	}
};


#endif
