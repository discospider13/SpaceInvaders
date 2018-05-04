#ifndef ALIEN_H
#define ALIEN_H

#include "Shape.h"

class Alien : public Shape {
public:
	float r, g, b;
	float loc_x, loc_y, loc_z;
	int state;
	int count;
	int respawn;
	bool boss;
	bool toDraw;
	Alien() {}
	~Alien() {}
	virtual void draw() {}
	virtual void drawNormal() {}
	virtual void nextState() {}
};

#endif

