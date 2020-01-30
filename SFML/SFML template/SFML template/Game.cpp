#include "Game.h"


Game::Game(int screenwidth, int screenheight, const std::string& title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title),
	board(screenwidth,screenheight),
	snake( { 2, 2 }),
	food(board)
{

}


void Game::render() {		//rendering

	if (!GameOver) {
		for (int i = 0; i < board.GetxTilesNum(); ++i) {
			for (int j = 0; j < board.GetyTilesNum(); ++j) {
				board.DrawTiles({ i , j }, sf::Color::Blue, createwindow);
			}
		}

		food.DrawFood(board, createwindow);
		snake.DrawSnake(board, createwindow);
	}

		createwindow.display();
	
}

void Game::main_menu()
{
	
}

void Game::update() {		//update game 

		++FrameCounter;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			direction = "right";
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			direction = "left";
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			direction = "up";
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			direction = "down";
		}


		if (FrameCounter >= FramePeriod) {


			controls.DetermineDirection(direction, snake);	//determine direction vector based on keyboard events
			snake.Follow();									//calls snake to follow up
			directionLoc = controls.GetDirectionVector();	// set direction vector
			snake.MoveHead(directionLoc);				//move snake head
			

			if (snake.CollideItself() || snake.CollideWithWalls(board)) {
				GameOver = true;
			}

			if (food.isEaten(snake)) {
				snake.EatenFood();
				food.respawn(snake);
			}

			FrameCounter = 0;
		}

		createwindow.clear();
	
}


bool Game::quit()			//call quit game

//DO NOT DELETE CONTENTS OF THIS FUNCTION TO PREVENT AN UNRESPONSIV SCREEN//
{
	while (createwindow.pollEvent(event)) {		//NON BLOCKING FUNCTION, WILL NOT GET STUCK IN WHILE LOOP.
		if (event.type == sf::Event::Closed) {
			createwindow.close();
			quitgame = true;
		}
	}
	return quitgame;
	
}

Game::~Game()	{}