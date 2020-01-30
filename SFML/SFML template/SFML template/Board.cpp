#include "Board.h"



Board::Board(const int screenwidth, const int screenheight)
	:drawtile(sf::Vector2f(TileDimensions, TileDimensions)),
	screenheight(screenheight),
	screenwidth(screenwidth)
{
	xTilesNum = screenwidth / TileDimensions;			//detemine nubmer of tiles
	yTilesNum = screenheight / TileDimensions;			//determine number of tiles
	
}

void Board::DrawTiles(const Location& loc, const sf::Color &color, sf::RenderWindow& createwindow)
{
	
	drawtile.setOutlineColor(sf::Color::Black);
	drawtile.setPosition(loc.x * TileDimensions, loc.y* TileDimensions);
	drawtile.setOutlineThickness(-TileOutlineThickness);
	
	
	drawtile.setFillColor(color);		//color of rectangle
	createwindow.draw(drawtile);

}

int Board::GetxTilesNum() const
{
	return xTilesNum;
}

int Board::GetyTilesNum() const
{
	return yTilesNum;
}

int Board::GetScreenWidth() const
{
	return screenwidth;
}

int Board::GetScreenHeight() const
{
	return screenheight;
}
