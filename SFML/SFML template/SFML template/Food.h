#pragma once
//food for the snake
#include "Location.h"
#include "Board.h"
#include "Snake.h"
#include <random>
#include <SFML\Audio.hpp>


class Food {
public:
	Food(const Board& board);
	void respawn(Snake& snake);		//respawn after eaten
	bool isEaten(const Snake& snake);	//checks to see if its eaten
	void DrawFood(Board& board, sf::RenderWindow& createwindow);	//draw the food
	Location GetFoodLoc() const;	//get the location of the food


private:
	Location FoodLoc;		//food location
	std::mt19937 rng;		//rng
	std::uniform_int_distribution<int> Xpos;	//rng
	std::uniform_int_distribution<int> Ypos;	//rng
	int xloc, yloc;						//x and y location for food.
	sf::Music sound;					//sound for eating the food
	
	



};