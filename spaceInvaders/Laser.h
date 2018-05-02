#ifndef LASER_H
#define LASER_H

#include "Shape.h";

class Laser : public Shape {
public:
	float locX, locY, locZ;
	bool dir;

	Laser(float locX, float locY, float locZ, bool dir)
	{
		this->locX = locX;
		this->locY = locY;
		this->locZ = locZ;
		this->dir = dir;
	}

	void draw()
	{
		glPushMatrix();
		glScalef(0.05, 0.05, 0.25);
		glColor3f(1.0, 0.0, 0.0);
		glutSolidCube(1.0);
		glPopMatrix();
	}

	void drawNormal() {}
};

#endif
