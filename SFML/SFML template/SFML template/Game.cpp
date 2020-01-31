#include "Game.h"


Game::Game(const int screenwidth, const int screenheight, const std::string& title, int framerate)
	:createwindow(sf::VideoMode(screenwidth, screenheight), title),
	board(screenwidth,screenheight),
	snake( { 2, 2 }),
	food(board)
{
	mainmusic.openFromFile("Harmony.ogg");
	mainmusic.setLoop(true);
	mainmusic.setVolume(30);
	mainmusic.play();
}


void Game::render() {		//rendering

	if (GameOver) {
		GameOvertexture.loadFromFile("game_over.png");
		gameoversprite.setTexture(GameOvertexture);
		createwindow.draw(gameoversprite);
		if (gameoverCounter == 1) {
			game_over();				//paly death music
			++gameoverCounter;		//prevent function from playing music again
			
		}
	}

	if (MainMenu && !GameOver) {
		main_menu();
	}

	if (!GameOver && !MainMenu) {
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
	loadtexture.loadFromFile("main_menu.png");
	sprite.setTexture(loadtexture);
	createwindow.draw(sprite);
	
}

void Game::game_over()
{
	
	mainmusic.stop();
	mainmusic.openFromFile("Death.wav");
	mainmusic.setLoop(false);
	mainmusic.setVolume(17);
	mainmusic.play();
	
}

void Game::update() {		//update game 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		MainMenu = false;
	}

	if (!GameOver && !MainMenu) {

		

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
				gameoverCounter += 1;
			}

			if (food.isEaten(snake)) {
				snake.EatenFood();
				food.respawn(snake);
			}
			FrameCounter = 0;
		}
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