#ifndef ALIENZERO_H
#define ALIENZERO_H

#include "Alien.h"

class AlienZero : public Alien {
public:
	AlienZero() {
		this->loc_x = 0;
		this->loc_y = 0;
		this->loc_z = 0;
	}

	AlienZero(float x, float y, float z) {
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

