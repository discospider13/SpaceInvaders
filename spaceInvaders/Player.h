#ifndef PLAYER_H
#define PLAYER_H

#include "Shape.h"

enum MOVE_DIRECTION {
	MV_RT = 0,
	MV_LT = 1,
	MV_UP = 2,
	MV_DN = 3,
};

class Player : public Shape {
private:
	float loc_x, loc_y, loc_z;
	float r, g, b;
	float speed;
	int canFire = 0;

public:
	Player(float x, float y, float z, float speed) {
		this->loc_x = x;
		this->loc_y = y;
		this->loc_z = z;
		this->r = 0.0;
		this->g = 1.0;
		this->b = 0.0;
		this->speed = speed;
	}

	int getNumFire()
	{
		return canFire;
	}

	void resetFire()
	{
		canFire = 14;
	}

	void decFire()
	{
		if (canFire > 0)
		{
			canFire--;
		}
	}

	void draw() {

		//block width of each segment
		int sec_0 = 1;
		int sec_1 = 3;
		int sec_2 = 7;
		int sec_3 = 9;

		//height of each segment
		int ht_0 = 1;
		int ht_1 = 2;
		int ht_2 = 1;
		int ht_3 = 2;

		//draw nose
		glPushMatrix();
		glTranslatef(this->loc_x, this->loc_y, this->loc_z);
		glScalef(0.1, 0.1, 0.1);
		glColor3f(this->r, this->g, this->b);
		glutSolidCube(1.0);

		//draw section 1
		glPushMatrix();
		glTranslatef(-1.0f, 0.0f, 0.0f);
		for (int i = 0; i < ht_1; i++) {
			glTranslatef(0.0f, 0.0f, 1.0f);
			for (float j = 0; j < sec_1; j++) {
				glPushMatrix();
				glTranslatef(j, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}

		//draw section 2
		glPushMatrix();
		glTranslatef(-2.0f, 0.0f, 0.0f);
		for (int i = 0; i < ht_2; i++) {
			glTranslatef(0.0f, 0.0f, 1.0f);
			for (float j = 0; j < sec_2; j++) {
				glPushMatrix();
				glTranslatef(j, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}

		//draw section 3
		glPushMatrix();
		glTranslatef(-1.0f, 0.0f, 0.0f);
		for (int i = 0; i < ht_3; i++) {
			glTranslatef(0.0f, 0.0f, 1.0f);
			for (float j = 0; j < sec_3; j++) {
				glPushMatrix();
				glTranslatef(j, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
		}
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}

	void drawNormal() {

	}

	void move(float dist, int dir) {
		switch (dir) {
		case MV_UP:
			this->loc_y += dist;
			break;
		case MV_DN:
			this->loc_y -= dist;
			break;
		case MV_RT:
			this->loc_x += dist;
			break;
		case MV_LT:
			this->loc_x -= dist;
			break;
		}
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
