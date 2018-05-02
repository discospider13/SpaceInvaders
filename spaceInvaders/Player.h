#ifndef PLAYER_H
#define PLAYER_H

#include "Shape.h"

class Player : public Shape {
private:
	float loc_x, loc_y, loc_z;

public:
	Player(float x, float y, float z) {
		this->loc_x = x;
		this->loc_y = y;
		this->loc_z = z;
	}

	void draw() {
		glPushMatrix();
		glTranslatef(this->loc_x, this->loc_y, this->loc_z);
		glColor3f(1.0f, 1.0f, 1.0f);
		glutSolidCube(1.0);
		glPopMatrix();
	}

	void drawNormal() {

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
