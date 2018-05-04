#ifndef STARS_H
#define STARS_H

#include "Shape.h"
#include <math.h>
#include <time.h>

using namespace std;

class Stars : public Shape {
private:
	int num;
	float min_x, min_y, min_z;
public:
	Stars(float x, float y, float z, int n) {
		this->min_x = x;
		this->min_y = y;
		this->min_z = z;
		this->num = n;
	};

	void draw() {
		srand(time(0));
		float r, g, b;
		float x, y, z;

		glBegin(GL_POINTS);
		for (int i = 0; i < num; i++) {
			//generate color
			r = (rand() % 100) / 100.0;
			g = (rand() % 100) / 100.0;
			b = (rand() % 100) / 100.0;

			//generate location
			x = ((rand() % 20) - 10.0) + this->min_x;
			y = ((rand() % 20) - 10.0) + this->min_y;
			z = ((rand() % 20) - 10.0) + this->min_z;

			//draw point
			glColor3f(r,g,b);
			glVertex3f(x,y,z);
		}
		glEnd();

	}

	void drawNormals() {}
};



#endif
