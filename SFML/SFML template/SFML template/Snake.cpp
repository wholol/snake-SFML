#include "Snake.h"

Snake::Snake(const Location& headLoc)
{
	for (int i = 0; i < segmentNumber; ++i) {
		segment.emplace_back();	//default construct 100 segments.
	}
	segment[0].inithead(headLoc);			//initialize location of the snake
}

void Snake::Follow()
{
	for (int i = segmentCounter; i > 0; --i) {
		segment[i].Follow(segment[i - 1]);
	}
}

void Snake::MoveHead(const Location& delta_pos)				//moves the ehad of the snake
{
	segment[0].MoveHead(delta_pos);							//moves the head by delta pos
}

bool Snake::CollideItself()			//see if head collides with itself
{
	for (int i = 1; i <= segmentCounter; ++i) {
		if (segment[0].GetSegmentLocation() == segment[i].GetSegmentLocation()) {
			return true;
		}
	}

	return false;
}

bool Snake::CollideWithWalls(const Board & board)		//checks if the snake collide with walls
{
	
	if (segment[0].GetSegmentLocation().x >= board.GetxTilesNum() || segment[0].GetSegmentLocation().y >= board.GetyTilesNum()
		|| segment[0].GetSegmentLocation().x < 0 || segment[0].GetSegmentLocation().y < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Snake::PreventFoodSpawnInBody(const Location & Foodloc)
{
	for (int i = 0; i < segmentCounter; ++i) {
		if (Foodloc == segment[i].GetSegmentLocation()) {
			return true;
		}
	}
	return false;
}

void Snake::DrawSnake(Board& brd,sf::RenderWindow& createwindow)				//draw the whole snake
{
	for (int i = 0; i < segmentCounter; ++i) {
		segment[i].drawSegment(brd,createwindow);
	}
}

bool Snake::checkReverse(const Location& delta_loc)
{
	return ((segment[0].GetSegmentLocation() += delta_loc) == segment[1].GetSegmentLocation());

}

void Snake::EatenFood()
{
	segmentCounter = segmentCounter + 1;
		
}

Location Snake::getHeadLocation() const
{
	return segment[0].GetSegmentLocation();
}

void Snake::Segments::inithead(const Location& headLoc)
{
	snakeloc = headLoc;	//assign snake location in the board.
}

void Snake::Segments::Follow(const Segments& next_segment)		//assign the previous postion to the curernt snake lcoation
{
	snakeloc = next_segment.snakeloc;
}

void Snake::Segments::drawSegment(Board& brd, sf::RenderWindow& createwindow)
{
	 brd.DrawTiles(snakeloc, sf::Color::Green,createwindow);
}

void Snake::Segments::MoveHead(const Location& delta_pos)			//moves the head by delta position
{
	snakeloc += delta_pos;
}

Location Snake::Segments::GetSegmentLocation() const			//gets the location of each segments.
{
	return snakeloc;
}
