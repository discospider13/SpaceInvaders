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
	int level = 0;
	bool bossfight = false;
	bool endboss = false;
public:

	void setDiff(int diff)
	{
		this->level = 0;
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

	int getLevel()
	{
		return level;
	}

	void setLevel(int level)
	{
		this->level = level;
		if (level == 4)
		{
			bossfight = true;
		}
		else if (level > 4)
		{
			endboss = true;
		}
	}

	bool isBossfight()
	{
		return bossfight;
	}

	bool checkEnd()
	{
		return endboss;
	}

	void spawnBoss(AlienControl& aliens)
	{
		aliens.spawn(0, 0, -6, 3);
	}

	void spawn(AlienControl& aliens)
	{
		this->level++;
		if (this->level == 4)
		{
			bossfight = true;
			spawnBoss(aliens);
		}
		else if (this->level > 4)
		{
			endboss = true;
		}
		else
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
	}

	void killboss(AlienControl& aliens, LaserControl& lasers, Player* player)
	{
		if (shotclock == 0)
		{
			srand(time(NULL));
			for (int i = 0; i < diff; i++)
			{
				int r;
				int loopguard = 20;
				bool exit = false;
				while (!exit)
				{
					if (loopguard < 0)
					{
						exit = true;
					}
					else
					{
						loopguard--;
					}
					r = rand() % aliens.aliens.size();
					if (aliens.aliens.at(r)->toDraw)
					{
						if (aliens.aliens.at(r)->loc_x > player->getLocX() - 1.25 && aliens.aliens.at(r)->loc_x < player->getLocX() + 1.25)
						{
							exit = true;
						}
					}
				}
				if (loopguard >= 0)
				{
					lasers.create(aliens.aliens.at(r)->loc_x, aliens.aliens.at(r)->loc_y, aliens.aliens.at(r)->loc_z, true);
				}
			}
			shotclock = 75;
		}
		else
		{
			shotclock--;
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
				int loopguard = 20;
				bool exit = false;
				while (!exit)
				{
					if (loopguard < 0)
					{
						exit = true;
					}
					else
					{
						loopguard--;
					}
					r = rand() % aliens.aliens.size();
					if (aliens.aliens.at(r)->toDraw)
					{
						if (aliens.aliens.at(r)->loc_x > player->getLocX() - 1.25 && aliens.aliens.at(r)->loc_x < player->getLocX() + 1.25)
						{
							exit = true;
						}
					}
				}
				if (loopguard >= 0)
				{
					lasers.create(aliens.aliens.at(r)->loc_x, aliens.aliens.at(r)->loc_y, aliens.aliens.at(r)->loc_z, true);
				}
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