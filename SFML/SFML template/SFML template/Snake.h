#pragma once
#include "Board.h"
#include "Location.h"



class Snake {		//main class : responsible for the whole snake. (std::vector of segments).

public:
	Snake(const Location& headLoc);				//initilaize the head
	void Follow();			//allows segments to follow head
	void MoveHead(const Location& delta_pos);			//moves the snake
	bool CollideItself();		//checks if the snake collides with itself. (i.e head collides with body location)
	bool CollideWithWalls(const Board& board);		//checks if it collides with the walls
	bool PreventFoodSpawnInBody(const Location& FoodLoc);	//prevent food to spawn in snake
	void DrawSnake(Board& brd, sf::RenderWindow& createwindow);
	bool checkReverse(const Location& delta_loc);			//checks if the user attempts to reverse into itself
	void EatenFood();				//chcks if the food is eaten
	Location getHeadLocation() const;

private:
	class Segments {	//this class : reponsible for the segments individually.
	public:
		void inithead(const Location& headLoc);			//initialize the head
		void Follow(const Segments& next_segment);			//moves the segment
		void drawSegment(Board& brd, sf::RenderWindow& createwindow);						//the board is passed by reference. SHOULD drawn on it own
		void MoveHead(const Location& delta_pos);
		Location GetSegmentLocation() const;

	private:
		Location snakeloc;
	};

private:
	
	std::vector<Segments> segment;
	static constexpr int segmentNumber = 200;
	int segmentCounter = 1;		//counter should not exceed 199.
	





};