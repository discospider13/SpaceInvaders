#ifndef ALIENCONTROL_H
#define ALIENCONTROL_H
#include <vector>
#include "Alien.h"
#include "AlienZero.h"
#include "AlienOne.h"
#include "AlienTwo.h"
#include "AlienThree.h"

class AlienControl
{
public:
	vector<Alien*> aliens;
	vector<Alien*>::iterator it;
	vector<Laser>::iterator lit;

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
		case 2:
			temp = new AlienTwo(x, y, z);
			aliens.push_back(temp);
			break;
		case 3:
			temp = new AlienThree(x, y, z);
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
	
	void collide(vector<Laser>& lasers)
	{
		it = aliens.begin();
		lit = lasers.begin();
		for (int i = 0; i < aliens.size(); i++, it++)
		{
			for (int j = 0; j < lasers.size(); j++, lit++)
			{
				if (lasers.at(j).locY == aliens.at(i)->loc_y)
				{
					if (lasers.at(j).locZ + 0.15 > aliens.at(i)->loc_z && lasers.at(j).locZ - 0.15 < aliens.at(i)->loc_z)
					{
						if (lasers.at(j).locX > aliens.at(i)->loc_x - 1 && lasers.at(j).locX < aliens.at(i)->loc_x + 1)
						{
							it = aliens.erase(it);
							lit = lasers.erase(lit);
						}
					}
				}
			}
		}
	}
	
};


#endif