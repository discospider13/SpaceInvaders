#ifndef ALIENTWO_H
#define ALIENTWO_H

#include "Alien.h"
#include "Shape.h"

class AlienTwo : public Alien {
public:
	AlienTwo() {
		this->loc_x = 0;
		this->loc_y = 0;
		this->loc_z = 0;
		this->state = 0;
		this->count = 14;
		this->boss = false;
		this->toDraw = true;
		this->respawn = 300;
		this->r = 0.0;
		this->g = 1.0;
		this->b = 0.0;
	}

	AlienTwo(float x, float y, float z) {
		this->loc_x = x;
		this->loc_y = y;
		this->loc_z = z;
		this->state = 0;
		this->count = 14;
		this->boss = false;
		this->toDraw = true;
		this->respawn = 300;
		this->r = 0.0;
		this->g = 1.0;
		this->b = 0.0;
	}

	void draw() {
		//state = 0 : legs curled in
		//state = 1 : legs open

		glPushMatrix();
		glTranslatef(this->loc_x, this->loc_y, this->loc_z);
		glScalef(0.1, 0.1, 0.1);
		glColor3f(this->r, this->g, this->b);

		//largest segment
		glPushMatrix();
		glTranslatef(-4.0, 0.0, 0.0);
		for (int i = 0; i < 8; i++) {
			glPushMatrix();
			glTranslatef(1.0 * i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//eye level
		glPushMatrix();
		glTranslatef(-4.0, 1.0, 0.0);
		for (int i = 0; i < 8; i++) {
			if (i != 2 && i != 5) {
				glPushMatrix();
				glTranslatef(1.0 * i, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}
		glPopMatrix();

		//1 above eyes
		glPushMatrix();
		glTranslatef(-3.0, 2.0, 0.0);
		for (int i = 0; i < 6; i++) {
			glPushMatrix();
			glTranslatef(1.0 * i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//2 above eyes
		glPushMatrix();
		glTranslatef(-2.0, 3.0, 0.0);
		for (int i = 0; i < 4; i++) {
			glPushMatrix();
			glTranslatef(1.0 * i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslatef(-1.0, 4.0, 0.0);
		for (int i = 0; i < 2; i++) {
			glPushMatrix();
			glTranslatef(1.0 * i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//mouth level
		glPushMatrix();
		glTranslatef(-3.0, -1.0, 0.0);
		if (this->state == 0) {
			for (int i = 0; i < 6; i++) {
				if (i != 1 && i != 4) {
					glPushMatrix();
					glTranslatef(1.0 * i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		else if (this->state == 1) {
			glTranslatef(1.0, 0.0, 0.0);
			for (int i = 0; i < 4; i++) {
				if (i == 0 || i == 3) {
					glPushMatrix();
					glTranslatef(1.0 * i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		glPopMatrix();

		//1 below mouth
		glPushMatrix();
		glTranslatef(-4.0, -2.0, 0.0);
		if (this->state == 0) {
			for (int i = 0; i < 8; i++) {
				if (i == 0 || i == 7) {
					glPushMatrix();
					glTranslatef(1.0 * i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		else if (this->state == 1) {
			glTranslatef(1.0, 0.0, 0.0);
			for (int i = 0; i < 6; i++) {
				if (i != 1 && i != 4) {
					glPushMatrix();
					glTranslatef(1.0 * i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		glPopMatrix();

		//bottom
		glPushMatrix();
		glTranslatef(-3.0, -3.0, 0.0);
		if (this->state == 0) {
			for (int i = 0; i < 6; i++) {
				if (i == 0 || i == 5) {
					glPushMatrix();
					glTranslatef(1.0 * i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		else if (this->state == 1) {
			glTranslatef(-1.0, 0.0, 0.0);
			for (int i = 0; i < 8; i++) {
				if (i == 0 || i == 2 || i == 5 || i == 7) {
					glPushMatrix();
						glTranslatef(1.0 * i, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
				}
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

	void drawNormal() {

	}
};

#endif
