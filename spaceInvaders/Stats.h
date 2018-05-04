#ifndef STATS_H
#define STATS_H

#include <GL/glew.h>
#include <freeglut.h>

class Stats {
public:
	Stats() {}

	void drawText(const char** text, int length, int x, int y) {

		glMatrixMode(GL_PROJECTION);
		double *matrix = new double[16];
		glGetDoublev(GL_PROJECTION_MATRIX, matrix);
		glLoadIdentity();
		glOrtho(0, 1600, 0, 900, -5, 5);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glLoadIdentity();
		glRasterPos2i(x, y);
		glColor3f(1.0, 1.0, 1.0);
		for (int i = 0; i < length; i++) {
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
		}
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixd(matrix);
		glMatrixMode(GL_MODELVIEW);
	}
};

#endif