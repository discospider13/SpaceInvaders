#ifndef ALIENCONTROL_H
#define ALIENCONTROL_H
#include <vector>
#include "Alien.h"
#include "AlienZero.h"
#include "AlienOne.h"

class AlienControl
{
public:
	vector<Alien*> aliens;

	void spawn(float x, float y, float z, int id)
	{
		Alien* temp;
		switch (id)
		{
		case 0: 
			temp = new AlienZero(x, y, z);
			aliens.push_back(temp);
			break;
		case 1:
			temp = new AlienOne(x, y, z);
			aliens.push_back(temp);
			break;
		}
	}

	void nextState()
	{
		for (int i = 0; i < aliens.size(); i++)
		{
			aliens.at(i)->nextState();
		}
	}

	void draw()
	{
		for (int i = 0; i < aliens.size(); i++)
		{
			aliens.at(i)->draw();
		}
	}
};


#endif