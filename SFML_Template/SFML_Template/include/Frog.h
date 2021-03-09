#pragma once
#include <SFML/Graphics.hpp>

class Frog
{
private:
	//// VARIABLES ////
	int upoffset;
	int xoffset;
	bool animate;

	//// CLOCK ////
	sf::Clock timer;

public:
	Frog();

	//// FUNCTIONS ////
	void frames();
	void MoveDown();
	void MoveUp();
	void MoveRight();
	void MoveLeft();
	void reset();

	//// FROG SETUP ////
	sf::Texture frogTex;
	sf::Sprite frogSprite;
	sf::IntRect sourceSprite;
};
