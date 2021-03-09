#pragma once
#include <SFML/Graphics.hpp>


class obs
{
private:
	//// VARIABLES ////
	float Bwidth;
	float Bheight;
	float Gwidth;
	float Gheight;
	float Ywidth;
	float Yheight;
	float SLwidth;
	float SLheight;
	float SLoff;
	float MLwidth;
	float MLheight;
	float MLoff;
	float BLwidth;
	float BLheight;
	float BLoff;
	
	float x;

public:
	obs();

	float move;

	//// CARS ////
	sf::Sprite car1;
	sf::Sprite car2;
	sf::Sprite car3;
	sf::Sprite car4;
	sf::Sprite car5;
	sf::Sprite car6;
	sf::Sprite car7;
	sf::Sprite car8;
	sf::Sprite car9;
	sf::Sprite cars[9] = { car1, car2, car3, car4, car5, car6, car7, car8, car9 };

	sf::Texture Bcar;
	sf::Texture Gcar;
	sf::Texture Ycar;

	//// LOGS ////
	sf::Sprite log1;
	sf::Sprite log2;
	sf::Sprite log3;
	sf::Sprite log4;
	sf::Sprite log5;
	sf::Sprite log6;
	sf::Sprite log7;
	sf::Sprite log8;
	sf::Sprite log9;
	sf::Sprite logs[9] = { log1, log2, log3, log4, log5, log6, log7, log8, log9 };

	sf::Texture Slog;
	sf::Texture Mlog;
	sf::Texture Blog;

	//// FUNCTIONS ////
	void moveLeft();
	void moveRight();
};

