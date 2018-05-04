#ifndef ALIENTHREE_H
#define ALIENTHREE_H

#include "Alien.h"
#include "Shape.h"

class AlienThree : public Alien {
public:
	AlienThree() {
		this->loc_x = 0;
		this->loc_y = 0;
		this->loc_z = 0;
		this->state = 0;
		this->count = 14;
		this->boss = true;
		this->toDraw = true;
		this->respawn = 10000;
		this->r = 1.0;
		this->g = 0.0;
		this->b = 0.0;
	}

	AlienThree(float x, float y, float z) {
		this->loc_x = x;
		this->loc_y = y;
		this->loc_z = z;
		this->state = 0;
		this->count = 14;
		this->boss = true;
		this->toDraw = true;
		this->respawn = 10000;
		this->r = 1.0;
		this->g = 0.0;
		this->b = 0.0;
	}

	void draw() {
		glPushMatrix();
		glTranslatef(this->loc_x, this->loc_y, this->loc_z);
		glScalef(0.2, 0.2, 0.2);
		glColor3f(this->r, this->g, this->b);

		//longest segment
		glPushMatrix();
		glTranslatef(-8.0, 0.0, 0.0);
		for (int i = 0; i < 16; i++) {
			glPushMatrix();
			glTranslatef(1.0 * i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//eye level
		glPushMatrix();
		glTranslatef(-7.0, 1.0, 0.0);
		for (int i = 0; i < 14; i++) {
			if (i != 2 && i != 5 && i != 8 && i != 11) {
				glPushMatrix();
				glTranslatef(1.0 * i, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}
		glPopMatrix();

		//1 above eye level
		glPushMatrix();
		glTranslatef(-6.0, 2.0, 0.0);
		for (int i = 0; i < 12; i++) {
				glPushMatrix();
				glTranslatef(1.0 * i, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
		}
		glPopMatrix();

		//2 above eye level
		glPushMatrix();
		glTranslatef(-5.0, 3.0, 0.0);
		for (int i = 0; i < 10; i++) {
			glPushMatrix();
			glTranslatef(1.0 * i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslatef(-4.0, 4.0, 0.0);
		for (int i = 0; i < 8; i++) {
			glPushMatrix();
			glTranslatef(1.0 * i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//mouth level
		glPushMatrix();
		glTranslatef(-6.0, -1.0, 0.0);
		for (int i = 0; i < 12; i++) {
			if (i != 3 && i != 4 && i != 7 && i != 8) {
				glPushMatrix();
				glTranslatef(1.0 * i, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}
		glPopMatrix();

		//bottom
		glPushMatrix();
		glTranslatef(-5.0, -2.0, 0.0);
		for (int i = 0; i < 10; i++) {
			if (i == 0 || i == 9) {
				glPushMatrix();
				glTranslatef(1.0 * i, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}
		glPopMatrix();

		glPopMatrix();

	}

	void nextState()
	{
		if (count == 0)
		{
			if (state == 0)
			{
				state = 1;
			}
			else
			{
				state = 0;
			}
			count = 14;
		}
		else
		{
			count--;
		}
	}

	void drawNormal() {}
};

#endif