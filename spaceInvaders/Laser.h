#ifndef LASER_H
#define LASER_H

#include "Shape.h";

class Laser : public Shape {
private:
	float loc_x, loc_y, loc_z;
	float speed;

public:
	Laser(float x, float y, float z, float speed) {
		this->loc_x = x;
		this->loc_y = y;
		this->loc_z = z;
		this->speed = speed;
	}

	void draw() {
		glPushMatrix();
		glTranslatef(this->loc_x, this->loc_y, this->loc_z);
		glScalef(0.1f, 0.1f, 0.3f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidCube(1.0f);
		glPopMatrix();
	}

	void drawNormal() {};

	void fire() {
		this->loc_z += this->speed;
	}

	void setLocX(float x) {
		this->loc_x = x;
	}

	void setLocY(float y) {
		this->loc_y = y;
	}

	void setLocZ(float z) {
		this->loc_z = z;
	}

	float getLocX() {
		return this->loc_x;
	}

	float getLocY() {
		return this->loc_y;
	}

	float getLocZ() {
		return this->loc_z;
	}
};

#endif
