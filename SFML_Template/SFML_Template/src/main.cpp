#include <SFML/Graphics.hpp>
#include <iostream>
#include <Frog.h>
#include <obs.h>
#include <base.h>
#include <UI.h>

int main() 
{
	//// VARIABLES AND CLASSES ////
	int screen = 600;
	int lives = 3;
	Frog frog;
	obs car;
	base base;
	UI userUI;
	sf::Clock gameTime;

	// create a window with the constructor 
	sf::RenderWindow window(sf::VideoMode(screen, screen), "Frogger"); 

	// run until the user closes the window 
	while (window.isOpen()) 
	{

		// check all the user events 
		sf::Event event; 

		while (window.pollEvent(event))
		{
			// user has pressed the close button 

			if (event.type == sf::Event::Closed) 
				window.close();

			//// LISTENS FOR THESE EVENTS ONLY IF LIVES IS NOT 0 AND THE TOTAL TIME ELAPSED IS LESS THAN 120 SECONDS ////
			if (lives > 0 && gameTime.getElapsedTime().asSeconds() < 120 && base.score != 600)
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
						frog.MoveUp();

					if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
						frog.MoveDown();

					if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
						frog.MoveLeft();

					if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
						frog.MoveRight();
				}
				
		}

		//userUI.timeLeft.setString(std::to_string(userUI.t) + "/120");

		//// CALLS FUNCTIONS TO MAKE EVERYTHING MOVE ////
		userUI.gameTime();

		frog.frames();

		car.moveLeft();

		car.moveRight();


		//// KILLS FROG ON INTERSECTION WITH A CAR ////
		for (int n = 0; n < 9; n++)
		{
			if (frog.frogSprite.getGlobalBounds().intersects(car.cars[n].getGlobalBounds()))
			{
				if (lives > 1)
				{
					frog.reset();		// resets frog position
					userUI.death();		// updates the lives UI
					lives--;			// decrements the number of lives
				}
				else
				{
					frog.reset();		// resets frog position
					userUI.death();		// updates the lives UI
					lives = 0;			// sets lives to 0
				}
			}
		}


		//// KILLS FROG ON INTERSECTION WITH WATER & UPDATES ITS POSITION TO THAT OF THE LOG ITS ON ////
		int z = -1;

		if (frog.frogSprite.getPosition().y < 260 && frog.frogSprite.getPosition().y > 90)		// if frog is between water boundaries
		{
			for (int n = 0; n < 9; n++)
			{
				if (frog.frogSprite.getGlobalBounds().intersects(car.logs[n].getGlobalBounds()))		// checks if frog is intersecting a log
				{
					z = n;		// sets value n to log number

					if (event.type != sf::Event::KeyPressed)
					{
						if (n < 3)
							frog.frogSprite.move(car.move, 0);		// makes the frogs position match the log until a kep is pressed
						else
						{
							if (n < 6)
								frog.frogSprite.move((-car.move - 0.02), 0);
							else
								frog.frogSprite.move((-car.move - 0.01), 0);
						}
					}

				}
			}
			if (z == -1)		// if z is its initial value -- frog is not on a log
			{
				if (lives > 1)
				{
					frog.reset();		// resets frog position
					userUI.death();		// updates the lives UI
					lives--;			// decrements the number of lives
				}
				else
				{
					frog.reset();		// resets frog position
					userUI.death();		// updates the lives UI
					lives = 0;			// sets lives to 0
				}
			}
		}
	

		//// ON INTERSECTION WITH A BASE ////
		for (int n = 0; n < 3; n++)
		{
			if (frog.frogSprite.getGlobalBounds().intersects(base.bases[n].getGlobalBounds()))		// checks if frog is intersecting base
			{
				base.reached();		// updates score
				base.bases[n].setColor(sf::Color(255, 255, 255, 255));		// changes the alpha to show its been reached
				frog.reset();		// resets frog position
			}
		}


		//// DRAWING ////
		window.clear();
		window.draw(userUI.Sbg);
		for (int n = 0; n < 9; n++)
		{
			window.draw(car.cars[n]);
			window.draw(car.logs[n]);
		}
		for (int n = 0; n < 3; n++)
		{
			window.draw(base.bases[n]);
			window.draw(userUI.lives[n]);
			window.draw(userUI.deaths[n]);
		}
		window.draw(userUI.timeBar);
		window.draw(userUI.life);
		window.draw(userUI.time);
		window.draw(frog.frogSprite);


		//// ON WIN ////
		if (base.score == 600)
		{
			userUI.timeDown = false;		// sets the bool to false to stop the game timer
			userUI.score.setString("Score: " + std::to_string((base.score + (lives * 20) + userUI.t)));		// sets the score string
			//// DRAWS VALUES FOR WIN GAME SCREEN ////
			window.draw(userUI.gameOver);
			window.draw(userUI.win);
			window.draw(userUI.frogs);
			window.draw(userUI.score);
		}


		//// ON LOSS ////
		if ((lives == 0) || (gameTime.getElapsedTime().asSeconds() > 120 && base.score != 600))
		{
			userUI.timeDown = false;		// sets the bool to false to stop the game timer
			userUI.score.setString("Score: " + std::to_string((base.score + (lives * 20))));		// sets the score string
			//// DRAWS VALUES FOR LOSS GAME SCREEN ////
			window.draw(userUI.gameOver);
			window.draw(userUI.over);
			window.draw(userUI.score);
		}

		window.display();
	}
	
	return 0; 
}