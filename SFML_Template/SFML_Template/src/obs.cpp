#include "obs.h"
#include <iostream>

obs::obs()
{
	move = 0.02f;		//default move value for all obstacles
	x = -40.f;		//initial x position for obstacles

	//// LOADS TEXTURES FOR ALL OBSTACLES ////
	Bcar.loadFromFile(".\\assets\\graphics\\Bcar.png");
	Gcar.loadFromFile(".\\assets\\graphics\\Gcar.png");
	Ycar.loadFromFile(".\\assets\\graphics\\Ycar.png");
	Slog.loadFromFile(".\\assets\\graphics\\Slog.png");
	Mlog.loadFromFile(".\\assets\\graphics\\Mlog.png");
	Blog.loadFromFile(".\\assets\\graphics\\Blog.png");


	//// SETS WIDTH AND HEIGHT FOR ALL OBSTACLES ////
	Bwidth = (Bcar.getSize().x * 0.75);
	Bheight = (Bcar.getSize().y * 0.75);
	Gwidth = (Gcar.getSize().x * 0.75);
	Gheight = (Gcar.getSize().y * 0.75);
	Ywidth = (Ycar.getSize().x * 0.75);
	Yheight = (Ycar.getSize().y * 0.75);
	SLwidth = Slog.getSize().x;
	SLheight = Slog.getSize().y;
	SLoff = (Slog.getSize().x * 0.5);
	MLwidth = Mlog.getSize().x;
	MLheight = Mlog.getSize().y;
	MLoff = (Mlog.getSize().x * 0.5);
	BLwidth = Blog.getSize().x;
	BLheight = Blog.getSize().y;
	BLoff = (Blog.getSize().x * 0.5);

	//// SETS VALUES FOR CAR 1-3 AND LOG 1-3 ////
	for (int n = 0; n < 3; n++)
	{
		cars[n].setScale(0.75, 0.75);
		cars[n].setTexture(Bcar);
		cars[n].setOrigin((Bwidth / 2), (Bheight / 2));
		cars[n].setPosition(x, 360);

		logs[n].setScale(0.5, 0.75);
		logs[n].setTexture(Slog);
		logs[n].setOrigin((SLwidth / 2), (SLheight / 2));
		logs[n].setPosition(x, 165);

		x = x - 250;
	}

	x = -40.f;		// resets x to be used in next variable initialisation

	//// SETS VALUES FOR CAR 4-6 ///
	for (int n = 3; n < 6; n++)
	{
		cars[n].setScale(0.75, 0.75);
		cars[n].setTexture(Gcar);
		cars[n].setOrigin((Gwidth / 2), (Gheight / 2));
		cars[n].setPosition(x, 495);

		x = x - 250;
	}

	x = 640.f;		// resets x to be used in next variable initialisation

	//// SETS VALUES FOR LOG 4-6 ////
	for (int n = 3; n < 6; n++)
	{
		logs[n].setScale(0.5, 0.75);
		logs[n].setTexture(Blog);
		logs[n].setOrigin((BLwidth / 2), (BLheight / 2));
		logs[n].setPosition(x, 100);

		x = x + 250;
	}

	x = 640.f;		// resets x to be used in next variable initialisation

	//// SETS VALUES FOR CAR 7-9 AND LOG 7-9 ////
	for (int n = 6; n < 9; n++)
	{
		cars[n].setScale(0.75, 0.75);
		cars[n].setTexture(Ycar);
		cars[n].setOrigin((Ywidth / 2), (Yheight / 2));
		cars[n].setPosition(x, 430);

		logs[n].setScale(0.5, 0.75);
		logs[n].setTexture(Mlog);
		logs[n].setOrigin((MLwidth / 2), (MLheight / 2));
		logs[n].setPosition(x, 230);

		x = x + 250;
	}
}

//// OBSTACLE MOVE FUNCTIONS ////

void obs::moveRight()
{
	for (int n = 0; n < 6; n++)
	{
		if (n < 3)
		{
			if (cars[n].getPosition().x > (600 + Bwidth))
				cars[n].setPosition((0 - Bwidth), 360);		// resets position if it goes off the edge of the screen
			else
				cars[n].move((move+0.005), 0);		// moves the obstacle across

			if (logs[n].getPosition().x > (600 + SLoff))
				logs[n].setPosition((0 - SLoff), 165);		// resets position if it goes off the edge of the screen
			else
				logs[n].move(move, 0);		// moves the obstacle across
		}
		else
		{
			if (cars[n].getPosition().x > (600 + Gwidth))
				cars[n].setPosition((0 - Gwidth), 495);		// resets position if it goes off the edge of the screen
			else
				cars[n].move((move+0.01), 0);		// moves the obstacle across
		}
	}
}


void obs::moveLeft()
{
	for (int n = 3; n < 9; n++)
	{
		if (n < 6)
		{
			if (logs[n].getPosition().x < (0 - SLoff))
				logs[n].setPosition((600 + SLoff), 100);		// resets position if it goes off the edge of the screen
			else
				logs[n].move((-move - 0.02), 0);		// moves the obstacle across
		}
		else
		{
			if (cars[n].getPosition().x < (0 - Ywidth))
				cars[n].setPosition((600 + Ywidth), 430);		// resets position if it goes off the edge of the screen
			else
				cars[n].move(-move, 0);		// moves the obstacle across

			if (logs[n].getPosition().x < (0 - SLoff))
				logs[n].setPosition((600 + SLoff), 230);		// resets position if it goes off the edge of the screen
			else
				logs[n].move((-move - 0.01), 0);		// moves the obstacle across
		}
	}
}