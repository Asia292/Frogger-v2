#include "base.h"
#include <iostream>

base::base()
{
	x = 95.f;		// initial x poition for bases
	score = 0;		// initial score

	baseTex.loadFromFile(".\\assets\\graphics\\frogb.png");		// loads base texture
	
	//// SETS VALUES FOR ALL BASES ////
	for (int n = 0; n < 3; n++)
	{
		bases[n].setTexture(baseTex);
		bases[n].setScale(0.8, 0.8);
		bases[n].setOrigin((baseTex.getSize().x / 2), (baseTex.getSize().y / 2));
		bases[n].setPosition(x, 45);
		bases[n].setColor(sf::Color(255, 255, 255, 0));

		x = x + 195;
	}
}

//// UPDATES THE SCORE WHEN A BASE IS REACHED ////
void base::reached()
{
	score = score + 200;
}
