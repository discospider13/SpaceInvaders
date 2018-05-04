#ifndef ALIENONE_H
#define ALIENONE_H

#include "Alien.h"

class AlienOne : public Alien {
public:
	AlienOne() {
		this->loc_x = 0;
		this->loc_y = 0;
		this->loc_z = 0;
		this->state = 0;
		this->count = 14;
		this->boss = false;
		this->toDraw = true;
		this->respawn = 300;
		this->r = 1.0;
		this->g = 0.0;
		this->b = 1.0;
	}

	AlienOne(float x, float y, float z) {
		this->loc_x = x;
		this->loc_y = y;
		this->loc_z = z;
		this->state = 0;
		this->count = 14;
		this->boss = false;
		this->toDraw = true;
		this->respawn = 300;
		this->r = 1.0;
		this->g = 0.0;
		this->b = 1.0;
	}

	void draw() {
		//state == 0 : legs curled in
		//state == 1 : legs flared out
		glPushMatrix();
		glTranslatef(this->loc_x, this->loc_y, this->loc_z);
		glScalef(0.1, 0.1, 0.1);
		glColor3f(this->r, this->g, this->b);

		//longest segment
		glPushMatrix();
		glTranslatef(-6.0, 0.0, 0.0);
		for (int i = 0; i < 12; i++) {
			glPushMatrix();
			glTranslatef(1.0*i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//eye-level
		glPushMatrix();
		glTranslatef(-6.0, 1.0, 0.0);
		for (int i = 0; i < 12; i++) {
			if (i != 3 && i != 4 && i != 7 && i != 8) {
				glPushMatrix();
				glTranslatef(1.0*i, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}
		glPopMatrix();

		//1 above eye-level
		glPushMatrix();
		glTranslatef(-6.0, 2.0, 0.0);
		for (int i = 0; i < 12; i++) {
			glPushMatrix();
			glTranslatef(1.0*i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//2 above eye-level
		glPushMatrix();
		glTranslatef(-5.0, 3.0, 0.0);
		for (int i = 0; i < 10; i++) {
			glPushMatrix();
			glTranslatef(1.0*i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslatef(-2.0, 4.0, 0.0);
		for (int i = 0; i < 4; i++) {
			glPushMatrix();
			glTranslatef(1.0*i, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		//mouth-level
		glPushMatrix();
		glTranslatef(-4.0, -1.0, 0.0);
		if (this->state == 0) {
			for (int i = 0; i < 8; i++) {
				if (i != 3 && i != 4) {
					glPushMatrix();
					glTranslatef(1.0*i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		else if (this->state == 1) {
			glTranslatef(1.0, 0.0, 0.0);
			for (int i = 0; i < 6; i++) {
				if (i != 2 && i != 3) {
					glPushMatrix();
					glTranslatef(1.0*i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		glPopMatrix();

		//upper-legs
		glPushMatrix();
		glTranslatef(-5.0, -2.0, 0.0);
		if (this->state == 0) {
			for (int i = 0; i < 10; i++) {
				if (i != 2 && i != 3 && i != 6 && i != 7) {
					glPushMatrix();
					glTranslatef(1.0*i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		else if (this->state == 1) {
			glTranslatef(1.0, 0.0, 0.0);
			for (int i = 0; i < 8; i++) {
				if (i != 2 && i != 5) {
					glPushMatrix();
					glTranslatef(1.0*i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		glPopMatrix();

		//lower-legs
		glPushMatrix();
		glTranslatef(-4.0, -3.0, 0.0);
		if (this->state == 0) {
			for (int i = 0; i < 8; i++) {
				if (i == 0 || i == 1 || i == 6 || i == 7) {
					glPushMatrix();
					glTranslatef(1.0*i, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
		}
		else if (this->state == 1) {
			glTranslatef(-2.0, 0.0, 0.0);
			for (int i = 0; i < 12; i++) {
				if (i == 0 || i == 1 || i == 10 || i == 11) {
					glPushMatrix();
					glTranslatef(1.0*i, 0.0, 0.0);
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
