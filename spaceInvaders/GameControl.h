#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#include "AlienControl.h"
#include "Alien.h"
#include "AlienZero.h"
#include "AlienOne.h"
#include "AlienTwo.h"
#include "AlienThree.h"

class GameControl
{
private:
	int diff;

public:

	void setDiff(int diff)
	{
		this->diff = diff;
	}

	int getDiff()
	{
		return diff;
	}

	void spawn(AlienControl& aliens)
	{
		for (int i = -3; i < 4; i++)
		{
			switch (diff)
			{
			case 3:
				aliens.spawn(i, 1, -6, 2);
				aliens.spawn(i, 1, -4, 1);
				aliens.spawn(i, 1, -2, 0);
			case 2:
				aliens.spawn(i, 0, -6, 2);
				aliens.spawn(i, 0, -4, 1);
				aliens.spawn(i, 0, -2, 0);
			case 1:
				aliens.spawn(i, -1, -6, 2);
				aliens.spawn(i, -1, -4, 1);
				aliens.spawn(i, -1, -2, 0);
			}
		}
	}
};

#endif