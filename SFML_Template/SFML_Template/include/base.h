#pragma once
#include <SFML/Graphics.hpp>


class base
{
private:
	//// VARIABLES ////
	float x;

public:
	base();

	int score;		// made public so it can be accessed in main.cpp
	
	//// BASES ////
	sf::Texture baseTex;
	sf::Sprite base1;
	sf::Sprite base2;
	sf::Sprite base3;

	sf::Sprite bases[3] = { base1, base2, base3 };

	//// FUNCTION ////
	void reached();
};

