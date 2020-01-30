#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Controls.h"


class Game {			//game class. should have render, update/events, quit and initialize.

public:
	Game(int screenwidth, int screenheight, const std::string& title, int framerate);	//game constructor
	Game &operator=(Game &other) = delete;				//prevent assigning game object
	Game(const Game& other) = delete;					//no deep copying a game object
	Game(Game &&other) = delete;						//no moving game object
	~Game();

	void main_menu();
	void update();					//update logic
	void render();					//render
	bool quit();					//quit the window


private:


	bool quitgame = false;			//quit game
	bool MainMenu = true;

	int FrameCounter = 0;						//frame counter
	static constexpr int FramePeriod = 7;		//frame period
	
	sf::Event event;					//events class
	sf::RenderWindow createwindow;		//windows class
	std::string direction = "right";	//initialize direction to right
	bool GameOver = false;				//gameover boolean

	/*game objects*/
	Board board;		//board class
	Snake snake;		//snake class
	Food food;			//food class
	Location directionLoc;	//direction location vector/struct
	Controls controls;	//controls of the snake
	
};