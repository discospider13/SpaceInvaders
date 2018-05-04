#ifndef BARRIERCONTROL_H
#define BARRIERCONTROL_H
#include "Barrier.h"
#include "Laser.h"
#include <vector>
using namespace std;

class BarrierControl
{
public:
	vector<Barrier> barriers;

	void create(int diff)
	{
		switch (diff)
		{
		case 1:
			barriers.push_back(Barrier(-3, -1, 0, 8));
			barriers.push_back(Barrier(0, -1, 0, 8));
			barriers.push_back(Barrier(3, -1, 0, 8));
			break;
		case 2:
			barriers.push_back(Barrier(-3, -1, 0, 5));
			barriers.push_back(Barrier(0, -1, 0, 5));
			barriers.push_back(Barrier(3, -1, 0, 5));
			barriers.push_back(Barrier(-3, 0, 0, 5));
			barriers.push_back(Barrier(0, 0, 0, 5));
			barriers.push_back(Barrier(3, 0, 0, 5));
			break;
		case 3:
			barriers.push_back(Barrier(-2, -1, 0, 5));
			barriers.push_back(Barrier(2, -1, 0, 5));
			barriers.push_back(Barrier(-2, 0, 0, 5));
			barriers.push_back(Barrier(2, 0, 0, 5));
			barriers.push_back(Barrier(-2, 1, 0, 5));
			barriers.push_back(Barrier(2, 1, 0, 5));
			break;
		}
	}

	void collide(vector<Laser>& lasers)
	{
		for (int i = 0; i < barriers.size(); i++)
		{
			for (int j = 0; j < lasers.size(); j++)
			{
				if (lasers.at(j).locY == barriers.at(i).loc_y && lasers.at(j).toDraw && barriers.at(i).toDraw && lasers.at(j).dir)
				{
					if (lasers.at(j).locZ + 0.15 > barriers.at(i).loc_z && lasers.at(j).locZ - 0.15 < barriers.at(i).loc_z)
					{
						if (lasers.at(j).locX > barriers.at(i).loc_x - 0.75 && lasers.at(j).locX < barriers.at(i).loc_x + 0.75)
						{
							barriers.at(i).hit();
							lasers.at(j).toDraw = false;
							return;
						}
					}
				}
				else if (lasers.at(j).locY == barriers.at(i).loc_y && lasers.at(j).toDraw && barriers.at(i).toDraw && !lasers.at(j).dir)
				{
					if (lasers.at(j).locZ + 0.15 > barriers.at(i).loc_z && lasers.at(j).locZ - 0.15 < barriers.at(i).loc_z)
					{
						if (lasers.at(j).locX > barriers.at(i).loc_x - 0.75 && lasers.at(j).locX < barriers.at(i).loc_x + 0.75)
						{
							lasers.at(j).toDraw = false;
							return;
						}
					}
				}
			}
		}
	}

	void draw()
	{
		for (int i = 0; i < barriers.size(); i++)
		{
			if (barriers.at(i).toDraw)
			{
				barriers.at(i).draw();
			}
		}
	}
};

#endif