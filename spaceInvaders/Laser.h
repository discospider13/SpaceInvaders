#ifndef LASER_H
#define LASER_H

#include "Shape.h";

class Laser : public Shape {
public:
	float locX, locY, locZ;
	float r, g, b;
	bool dir, toDraw = true;

	Laser(float locX, float locY, float locZ, bool dir)
	{
		this->locX = locX;
		this->locY = locY;
		this->locZ = locZ;
		this->dir = dir;
		if (dir)
		{
			this->r = 1.0;
			this->g = 0.0;
			this->b = 0.0;
		}
		else
		{
			this->r = 0.0;
			this->g = 1.0;
			this->b = 1.0;
		}
	}

	void draw()
	{
		glPushMatrix();
		glScalef(0.1, 0.1, 0.3);
		glColor3f(r,g,b);
		glutSolidCube(1.0);
		glPopMatrix();
	}

	void drawNormal() {}
};

#endif
