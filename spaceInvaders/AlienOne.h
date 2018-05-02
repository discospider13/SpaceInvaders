#ifndef ALIENONE_H
#define ALIENONE_H

#include "Alien.h"

class AlienOne : public Alien {
public:
	AlienOne() {
		this->loc_x = 0;
		this->loc_y = 0;
		this->loc_z = 0;
	}

	AlienOne(float x, float y, float z) {
		this->loc_x = x;
		this->loc_y = y;
		this->loc_z = z;
	}

	void draw() {

	}

	void drawNormal() {

	}
};

#endif
