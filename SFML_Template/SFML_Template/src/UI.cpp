#include "UI.h"
#include <iostream>


UI::UI()
{
	//// VARIABLES ////
	l = 2;		// used for number of lives
	x = 80;		// used for the x coordinate of the life and death sprites
	t = 120;	// used for time value#
	timeDown = true;	// controls when the time should go down

	//// TEXT ////
	neuro.loadFromFile(".\\assets\\font\\neuropol.ttf");	//loads in the font

	//// SETS LIFE TEXT PROPERTIES ////
	life.setFont(neuro);
	life.setString("Lives:");
	life.setCharacterSize(15);
	life.setPosition(10, 560);
	life.setFillColor(sf::Color::Black);
	life.setOutlineColor(sf::Color::White);
	life.setOutlineThickness(1);

	//// SETS GAMEOVER TEXT PROPERTIES ////
	over.setFont(neuro);
	over.setString("GAME OVER");
	over.setCharacterSize(50);
	over.setPosition(100, 220);
	over.setFillColor(sf::Color::Red);
	over.setOutlineColor(sf::Color::Yellow);
	over.setOutlineThickness(2);

	//// SETS SCORE TEXT PROPERTIES ////
	score.setFont(neuro);
	score.setCharacterSize(50);
	score.setPosition(130, 320);
	score.setFillColor(sf::Color::Red);
	score.setOutlineColor(sf::Color::Yellow);
	score.setOutlineThickness(2);

	//// SETS TIME TEXT PROPERTIES ////	
	time.setFont(neuro);
	time.setString("Time");
	time.setCharacterSize(10);
	time.setPosition(560, 558);
	time.setFillColor(sf::Color::Black);
	time.setOutlineColor(sf::Color::White);
	time.setOutlineThickness(1);

	/*timeLeft.setFont(neuro);
	//timeLeft.setString(std::to_string(t) + "/120");
	timeLeft.setCharacterSize(10);
	timeLeft.setPosition(510, 573);
	timeLeft.setFillColor(sf::Color::Black);
	timeLeft.setOutlineColor(sf::Color::White);
	timeLeft.setOutlineThickness(1);*/

	//// SETS WIN TEXT PROPERTIES ////
	win.setFont(neuro);
	win.setString("YOU WIN");
	win.setCharacterSize(50);
	win.setPosition(150, 100);
	win.setFillColor(sf::Color::Red);
	win.setOutlineColor(sf::Color::Yellow);
	win.setOutlineThickness(2);

	//// SETS FROG TEXT PROPERTIES ////
	frogs.setFont(neuro);
	frogs.setString("All your frogs made it to safety");
	frogs.setCharacterSize(25);
	frogs.setPosition(30, 220);
	frogs.setFillColor(sf::Color::Red);
	frogs.setOutlineColor(sf::Color::Yellow);
	frogs.setOutlineThickness(2);

	//// LIFE AND DEATH SPRITES ////
	lifeTex.loadFromFile(".\\assets\\graphics\\frogb.png");		//loads the image file

	for (int n = 0; n < 3; n++)		//defines the properties of all 3 life sprites
	{
		lives[n].setTexture(lifeTex);
		lives[n].setScale(0.5, 0.5);
		lives[n].setOrigin((lifeTex.getSize().x / 4), (lifeTex.getSize().y / 4));
		lives[n].setPosition(x, 565);
		lives[n].setColor(sf::Color(255, 255, 255, 255));

		x = x + 35;
	}

	x = 80;

	deathTex.loadFromFile(".\\assets\\graphics\\dead.png");		//loads the image file

	for (int n = 0; n < 3; n++)		//defines the properties of all 3 death sprites
	{
		deaths[n].setTexture(deathTex);
		deaths[n].setScale(0.4, 0.4);
		deaths[n].setOrigin((deathTex.getSize().x / 4), (deathTex.getSize().y / 4));
		deaths[n].setPosition(x, 562);
		deaths[n].setColor(sf::Color(255, 255, 255, 0));

		x = x + 35;
	}


	//// GAME TIMER ////
	timeBar.setSize(sf::Vector2f(120, 14));
	timeBar.setPosition(553, 565);
	timeBar.setOrigin(0, 7);
	timeBar.setFillColor(sf::Color::Red);
	timeBar.setRotation(180);

	//// BACKGROUND ////
	bg.loadFromFile(".\\assets\\graphics\\bg.png");		//loads the background image file
	Sbg.setTexture(bg);
	Sbg.setScale(0.83, 0.83);		//sets the background image properties

	
	gameOver.setFillColor(sf::Color(0, 0, 0, 150));
	gameOver.setSize(sf::Vector2f(600, 600));		//sets the properties for the greyed out game over screen
	gameOver.setPosition(0, 0);


	//// AUDIO ////
	loop.openFromFile(".\\assets\\audio\\PimPoy.wav");
	loop.setLoop(true);
	loop.play();
};


void UI::death()
{
	//// CHANGES THE ALPHA OF THE LIFE AND DEATH SPRITES SO THEY APPEAR TO SWAP ////
	lives[l].setColor(sf::Color(255, 255, 255, 0));
	deaths[l].setColor(sf::Color(255, 255, 255, 255));

	l--;
}

//// UPDATES THE TIME BAR ////
void UI::gameTime()
{
	if (game.getElapsedTime().asSeconds() > 1 && timeBar.getSize().x != 0 && timeDown)
	{
		timeBar.setSize(sf::Vector2f((timeBar.getSize().x - 1), 14));
		t = t - 1;
		game.restart();
	}
}