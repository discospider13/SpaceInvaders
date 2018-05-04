#ifndef STATS_H
#define STATS_H

#include <GL/glew.h>
#include <freeglut.h>
#include <iostream>

using namespace std;

class Stats {
public:
	Stats() {}

	void drawHealth(float x, float y, float z, int health) {
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

		glPushMatrix();
		glTranslatef(x - (health / 2.0) + 0.5, y - 0.5, z + 0.5);
		for (int i = 0; i < health; i++) {
			//draw nose
			glPushMatrix();
			glTranslatef(1.0 * i , 0.0, 0.0);
			glScalef(0.075, 0.075, 0.075);
			glColor3f(0.0, 1.0, 0.0);
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
		glPopMatrix();
	}

	void drawScore(float x, float y, float z, int score) {
		int val;

		int count = 0;

		do {
			val = score % 10;
			score /= 10;
			//cout << val << endl;
			//cout << score << endl;

			glPushMatrix();
			switch (val) {
			case (0):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(-1.0, 3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 1.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x >= 3) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(-2.0, 0.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x != 1 && x != 3) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -1.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x <= 1 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-1.0, -3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPopMatrix();
				break;
			case (1):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(0.0, 3.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.0, 2.0, 0.0);
				for (int x = 0; x < 2; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, 1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(0.0, 0.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, -1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();

				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, -2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-1.0, -3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();
				break;
			case (2):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(-1.0, 3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2.0, 1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(0.0, 0.0, 0.0);
				for (int x = 0; x < 2; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.0, -1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();

				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-2.0, -3.0, 0.0);
				for (int x = 0; x < 5; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();
				break;
			case (3):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(-2.0, 3.0, 0.0);
				for (int x = 0; x < 5; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2.0, 2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(1.0, 1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(0.0, 0.0, 0.0);
				for (int x = 0; x < 2; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2.0, -1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();

				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-1.0, -3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();
				break;
			case (4):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(1.0, 3.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0, 2.0, 0.0);
				for (int x = 0; x < 2; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.0, 1.0, 0.0);
				for (int x = 0; x < 3; x++) {
					if (x != 1) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(-2.0, 0.0, 0.0);
				for (int x = 0; x < 4; x++) {
					if (x == 0 || x == 3) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -1.0, 0.0);
				for (int x = 0; x < 5; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();

				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(1.0, -2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(1.0, -3.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();
				break;
			case (5):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(-2.0, 3.0, 0.0);
				for (int x = 0; x < 5; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(-1.0, 0.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2.0, -1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();

				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-1.0, -3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();
				break;
			case (6):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(0.0, 3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.0, 2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(-2.0, 0.0, 0.0);
				for (int x = 0; x < 4; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -1.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}

				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-1.0, -3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();
				break;
			case (7):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(-2.0, 3.0, 0.0);
				for (int x = 0; x < 5; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2.0, 2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(1.0, 1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(0.0, 0.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.0, -1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();

				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.0, -2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-1.0, -3.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();
				break;
			case (8):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(-1.0, 3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 1.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x >= 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(-1.0, 0.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -1.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, -2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-1.0, -3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPopMatrix();
				break;
			case (9):
				glPushMatrix();
				glTranslatef(x, y + 3.5, z);
				glColor3f(1.0, 1.0, 1.0);
				glScalef(0.1, 0.1, 0.1);

				//top
				glPushMatrix();
				glTranslatef(-1.0, 3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 2.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x == 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.0, 1.0, 0.0);
				for (int x = 0; x < 5; x++) {
					if (x == 0 || x >= 4) {
						glPushMatrix();
						glTranslatef(x * 1.0, 0.0, 0.0);
						glutSolidCube(1.0);
						glPopMatrix();
					}
				}
				glPopMatrix();

				//middle
				glPushMatrix();
				glTranslatef(-1.0, 0.0, 0.0);
				for (int x = 0; x < 4; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2.0, -1.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPushMatrix();
				glTranslatef(1.0, -2.0, 0.0);
				for (int x = 0; x < 1; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				//bottom
				glPushMatrix();
				glTranslatef(-2.0, -3.0, 0.0);
				for (int x = 0; x < 3; x++) {
					glPushMatrix();
					glTranslatef(x * 1.0, 0.0, 0.0);
					glutSolidCube(1.0);
					glPopMatrix();
				}
				glPopMatrix();

				glPopMatrix();
				break;
			}
			glTranslatef(1.5, 0.0, 0.0);
			glPopMatrix();
		} while (score > 0);
	}
	
};

#endif