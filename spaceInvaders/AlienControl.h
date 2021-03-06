#ifndef ALIENCONTROL_H
#define ALIENCONTROL_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Alien.h"
#include "AlienZero.h"
#include "AlienOne.h"
#include "AlienTwo.h"
#include "AlienThree.h"
#include "laser.h"
#include "Player.h"
using namespace std;

class AlienControl
{
public:
	vector<Alien*> aliens;
	int respawnTime = 300;
	int dir = -1;
	float dist = 0.0;

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
			if (aliens.at(i)->toDraw)
			{
				aliens.at(i)->draw();
			}
		}
	}
	
	void collide(vector<Laser>& lasers, int& score)
	{
		for (int i = 0; i < aliens.size(); i++)
		{
			for (int j = 0; j < lasers.size(); j++)
			{
				if (lasers.at(j).locY == aliens.at(i)->loc_y && lasers.at(j).toDraw && aliens.at(i)->toDraw && !lasers.at(j).dir)
				{
					if (lasers.at(j).locZ + 0.15 > aliens.at(i)->loc_z && lasers.at(j).locZ - 0.15 < aliens.at(i)->loc_z)
					{
						if (aliens.at(i)->boss)
						{
							if (lasers.at(j).locX > aliens.at(i)->loc_x - 1.5 && lasers.at(j).locX < aliens.at(i)->loc_x + 1.5)
							{
								srand(time(NULL));
								int r = rand();
								if ((r % 4) == 0)
								{
									aliens.at(i)->toDraw = false;
								}
								lasers.at(j).toDraw = false;
								score += 1000;
								return;
							}
						}
						else
						{
							if (lasers.at(j).locX > aliens.at(i)->loc_x - 0.75 && lasers.at(j).locX < aliens.at(i)->loc_x + 0.75)
							{
								aliens.at(i)->toDraw = false;
								lasers.at(j).toDraw = false;
								score += 50;
								return;
							}
						}
					}
				}
			}
		}
	}

	void bossMove(Player* player)
	{
		for (int i = 0; i < aliens.size(); i++)
		{
			aliens.at(i)->loc_y = player->getLocY();
		}
		move();
	}

	void move()
	{
		float movedist = dir * 0.05;
		if (movedist + dist > 2)
		{
			dist = 2 * dir;
			dir *= -1;
			movedist = dir * 0.05;
		}
		else if (abs(movedist) + abs(dist) > 2)
		{
			dist = 2 * dir;
			dir *= -1;
			movedist = dir * 0.05;
		}
		dist += movedist;
		for (int i = 0; i < aliens.size(); i++)
		{
			aliens.at(i)->loc_x += movedist;
		}
	}

	bool empty()
	{
		bool empty = true;
		for (int i = 0; i < aliens.size(); i++)
		{
			if (aliens.at(i)->toDraw)
			{
				empty = false;
			}
		}
		if (empty)
		{
			aliens.clear();
		}
		return empty;
	}

	void respawn()
	{
		for (int i = 0; i < aliens.size(); i++)
		{
			if (!aliens.at(i)->toDraw)
			{
				if (aliens.at(i)->respawn == 0)
				{
					aliens.at(i)->toDraw = true;
					aliens.at(i)->respawn = respawnTime;
					respawnTime -= 3;
				}
				else
				{
					aliens.at(i)->respawn--;
				}
			}
		}
	}
};


#endif