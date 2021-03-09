#include "Frog.h"
#include <iostream>

using namespace std;
Frog::Frog()
{
	upoffset = 65;		// distance frog can move up & down
	xoffset = 32;		// distance frog can move left & right
	animate = false;

	frogTex.loadFromFile(".\\assets\\graphics\\frog.png");		// loads the frog texture

	sourceSprite = sf::IntRect(0, 0, 55, 78);		// sets the default or 'source' sprite - first frame
	
	//// SETS FROG VALUES ////
	frogSprite.setScale(0.8, 0.8);
	frogSprite.setPosition(290, 560);
	frogSprite.setTexture(frogTex);
	frogSprite.setOrigin(27.5, (frogTex.getSize().y / 2));
	frogSprite.setTextureRect(sourceSprite);
}

//// USED TO ADVANCE THE FRAME OF THE FROG - ANIMATE THE FROG ////
void Frog::frames()
{
	if (timer.getElapsedTime().asSeconds() > (1.0f / 20.0f))
	{
		if (animate)
		{
			if (sourceSprite.left == 285)		// checks the left value of the current frame, if its 285 sets it to 0 and changes the animate bool to false to stop running this function
			{
				sourceSprite.left = 0;
				frogSprite.setTextureRect(sourceSprite);
				animate = false;
			}
			else
			{
				sourceSprite.left += 57;		// if the left value of frame isnt 285 increments it by 57
				frogSprite.setTextureRect(sourceSprite);
			}
		}
		timer.restart();		// restarts the timer
	}
}

//// MOVEMENT FUNCTIONS ////

void Frog::MoveDown()
{
	if (frogSprite.getRotation() != 180)
		frogSprite.setRotation(180);		// sets the rotation of the frog

	if (frogSprite.getPosition().y != 560)
		frogSprite.move(0, upoffset);		// moves the frog

	animate = true;		// makes the bool animate true so the function Frames will run
}

void Frog::MoveUp()
{
	if (frogSprite.getRotation() != 0)
		frogSprite.setRotation(0);		// sets the rotation of the frog

	if (frogSprite.getPosition().y != 100 || ((frogSprite.getPosition().x > 70) && (frogSprite.getPosition().x < 120)) || ((frogSprite.getPosition().x > 265) && (frogSprite.getPosition().x < 315)) || ((frogSprite.getPosition().x > 460) && (frogSprite.getPosition().x < 510)))
		frogSprite.move(0, -upoffset);		// moves the frog

	animate = true;		// makes the bool animate true so the function Frames will run
}

void Frog::MoveLeft()
{
	if (frogSprite.getRotation() != 270)
		frogSprite.setRotation(270);		// sets the rotation of the frog

	if (frogSprite.getPosition().x != 10)
		frogSprite.move(-xoffset, 0);		// moves the frog

	animate = true;		// makes the bool animate true so the function Frames will run
}

void Frog::MoveRight()
{
	if (frogSprite.getRotation() != 90)
		frogSprite.setRotation(90);		// sets the rotation of the frog

	if (frogSprite.getPosition().x != 590)
		frogSprite.move(xoffset, 0);		// moves the frog

	animate = true;		// makes the bool animate true so the function Frames will run
}


//// FROG RESET POSITION AND FRAME ////
void Frog::reset()
{
	frogSprite.setPosition(290, 560);
	sourceSprite.left = 0;
	frogSprite.setTextureRect(sourceSprite);
	frogSprite.setRotation(0);
}
