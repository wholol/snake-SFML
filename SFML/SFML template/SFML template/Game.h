#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Controls.h"


class Game {			//game class. should have render, update/events, quit and initialize.

public:
	Game(const int screenwidth, const int screenheight, const std::string& title, int framerate);	//game constructor
	Game &operator=(Game &other) = delete;				//prevent assigning game object
	Game(const Game& other) = delete;					//no deep copying a game object
	Game(Game &&other) = delete;						//no moving game object
	~Game();

	void main_menu();
	void game_over();
	void update();					//update logic
	void render();					//render
	bool quit();					//quit the window

	
private:

	
	bool quitgame = false;			//quit game (for close button)
	bool MainMenu = true;			//main menu 
	int gameoverCounter = 0;
	bool GameOver = false;				//gameover boolean
	
	sf::Music mainmusic;
	sf::Texture loadtexture;
	sf::Texture GameOvertexture;
	sf::Sprite sprite;
	sf::Sprite gameoversprite;

	int FrameCounter = 0;						//frame counter
	static constexpr int FramePeriod = 7;		//frame period
	
	sf::Event event;					//events class
	sf::RenderWindow createwindow;		//windows class
	std::string direction = "right";	//initialize direction to right
	

	/*game objects*/
	Board board;		//board class
	Snake snake;		//snake class
	Food food;			//food class
	Location directionLoc;	//direction location vector/struct
	Controls controls;	//controls of the snake
	
};