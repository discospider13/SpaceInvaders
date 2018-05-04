#ifndef LASERCONTROL_H
#define LASERCONTROL_H
#include "Laser.h"
#include <vector>
#include <iterator>
using namespace std;


class LaserControl
{
public:
	vector<Laser> laserList;
	float spd = 0.075;
	vector<Laser>::iterator it;
	
	void create(float x, float y, float z, bool dir)
	{
		Laser temp(x, y, z, dir);
		laserList.push_back(temp);
	}

	void move()
	{
		it = laserList.begin();
		for (int i = 0; i < laserList.size(); i++, it++)
		{
			if (laserList.at(i).dir)
			{
				laserList.at(i).locZ += spd;
			}
			else
			{
				laserList.at(i).locZ -= spd;
			}

			if (laserList.at(i).dir && laserList.at(i).locZ > 7)
			{
				it = laserList.erase(it);
			}
			else if(!laserList.at(i).dir && laserList.at(i).locZ < -7)
			{
				it = laserList.erase(it);
			}
		}
	}

	void draw()
	{
		for (int i = 0; i < laserList.size(); i++)
		{
			if (laserList.at(i).toDraw)
			{
				glPushMatrix();
				glTranslatef(laserList.at(i).locX, laserList.at(i).locY, laserList.at(i).locZ);
				laserList.at(i).draw();
				glPopMatrix();
			}
		}
	}
};

#endif