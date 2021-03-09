#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class UI
{
private:
	//// VARIABLES ////
	float x;
	int l;

public:
	UI();

	int t;		// made public so it can be accessed in main.cpp

	//// TEXT ////
	sf::Font neuro;
	sf::Text life;
	sf::Text over;
	sf::Text score;
	sf::Text time;
	sf::Text timeLeft;
	sf::Text win;
	sf::Text frogs;
	
	//// LIFE AND DEATH SPRITES ////
	sf::Texture lifeTex;
	sf::Sprite life1;
	sf::Sprite life2;
	sf::Sprite life3;

	sf::Sprite lives[3] = { life1, life2, life3 };


	sf::Texture deathTex;
	sf::Sprite death1;
	sf::Sprite death2;
	sf::Sprite death3;

	sf::Sprite deaths[3] = { death1, death2, death3 };

	//// BACKGROUND ////
	sf::Texture bg;
	sf::Sprite Sbg;

	sf::RectangleShape gameOver;

	//// GAME TIMER ////
	sf::RectangleShape timeBar;
	sf::Clock game;
	bool timeDown;

	//// FUNCTIONS ////
	void death();
	void gameTime();

	//// AUDIO ////
	sf::Music loop;
};

