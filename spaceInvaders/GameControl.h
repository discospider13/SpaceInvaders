#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#include "AlienControl.h"
#include "LaserControl.h"
#include "Alien.h"
#include "AlienZero.h"
#include "AlienOne.h"
#include "AlienTwo.h"
#include "AlienThree.h"
#include <time.h>
#include <cstdlib>

class GameControl
{
private:
	int diff;
	int gameMode;
	int shotclock = 75;
public:

	void setDiff(int diff)
	{
		this->diff = diff;
	}

	int getDiff()
	{
		return diff;
	}

	void setMode(int mode)
	{
		this->gameMode = mode;
	}

	int getMode()
	{
		return gameMode;
	}

	void spawn(AlienControl& aliens)
	{
		for (float i = -4.5; i < 5; i += 1.5)
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

	void shoot(AlienControl& aliens, LaserControl& lasers, Player* player)
	{
		if (shotclock == 0)
		{
			srand(time(NULL));
			for (int i = 0; i < diff; i++)
			{
				int r;
				bool exit = false;
				while (!exit)
				{
					r = rand() % aliens.aliens.size();
					if (aliens.aliens.at(r)->toDraw)
					{
						if (aliens.aliens.at(r)->loc_x > player->getLocX() - 1.25 && aliens.aliens.at(r)->loc_x < player->getLocX() + 1.25)
						{
							exit = true;
						}
					}
				}
				lasers.create(aliens.aliens.at(r)->loc_x, aliens.aliens.at(r)->loc_y, aliens.aliens.at(r)->loc_z, true);
			}
			shotclock = 75;
		}
		else
		{
			shotclock--;
		}
	}
};

#endif