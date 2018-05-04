#ifndef BARRIER_H
#define BARRIER_H

#include "Shape.h"

class Barrier : public Shape {
public:
	int max_hits, hits;
	bool toDraw;
	float loc_x, loc_y, loc_z;
	float r, g, b;

	Barrier(float x, float y, float z, int hits) {
		this->loc_x = x;
		this->loc_y = y;
		this->loc_z = z;
		this->r = 0.0;
		this->g = 1.0;
		this->b = 0.0;
		this->toDraw = true;
		this->max_hits = hits;
		this->hits = 0;
	}

	void draw() {
		glPushMatrix();
		glTranslatef(this->loc_x, this->loc_y, this->loc_z);
		glScalef(0.1, 0.1, 0.1);
		glColor3f((this->r + this->hits * (1.0/this->max_hits)), (this->g - this->hits * (1.0/this->max_hits)), this->b);

		for (int z = 0; z < (this->max_hits - this->hits); z++) {
			glPushMatrix();
			glTranslatef(0.0, -1.0*z, 0.0);
			//middle
			glPushMatrix();
			glTranslatef(-5.0, 0.0, 0.0);
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 11; x++) {
					glPushMatrix();
					glTranslatef(1.0*x, 0.0, 1.0*(y - 3));
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
			glPopMatrix();

			//top
			glPushMatrix();
			glTranslatef(-4.0, 0.0, -4.0);
			for (int x = 0; x < 9; x++) {
				glPushMatrix();
				glTranslatef(1.0*x, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-3.0, 0.0, -5.0);
			for (int x = 0; x < 7; x++) {
				glPushMatrix();
				glTranslatef(1.0*x, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-2.0, 0.0, -6.0);
			for (int x = 0; x < 5; x++) {
				glPushMatrix();
				glTranslatef(1.0*x, 0.0, 0.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
			glPopMatrix();

			//bottom
			glPushMatrix();
			glTranslatef(-5.0, 0.0, 1.0);
			for (int x = 0; x < 11; x++) {
				if (x < 4 || x > 6) {
					glPushMatrix();
					glTranslatef(1.0*x, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-5.0, 0.0, 2.0);
			for (int x = 0; x < 11; x++) {
				if (x < 3 || x > 7) {
					glPushMatrix();
					glTranslatef(1.0*x, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-5.0, 0.0, 3.0);
			for (int x = 0; x < 11; x++) {
				if (x < 2 || x > 8) {
					glPushMatrix();
					glTranslatef(1.0*x, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
			glPopMatrix();
			glPopMatrix();
		}
		glPopMatrix();
	}

	bool hit() {
		this->hits++;
		if (this->hits < this->max_hits) {
			return false;
		}
		else
		{
			toDraw = false;
			return true;
		}
	}

	void drawNormal() {}
};

#endif