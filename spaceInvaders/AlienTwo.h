#ifndef ALIENTWO_H
#define ALIENTWO_H

#include "Alien.h"

class AlienTwo : public Alien {
public:
	AlienTwo() {
		this->loc_x = 0;
		this->loc_y = 0;
		this->loc_z = 0;
	}

	AlienTwo(float x, float y, float z) {
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
