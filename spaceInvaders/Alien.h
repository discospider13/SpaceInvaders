#ifndef ALIEN_H
#define ALIEN_H

#include "Shape.h"

class Alien : public Shape {
protected:
	float r, g, b;
	float loc_x, loc_y, loc_z;

public:
	Alien() {}
	~Alien() {}
	void draw() {}
	void drawNormal() {}
};

#endif

