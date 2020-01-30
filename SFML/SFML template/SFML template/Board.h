#pragma once
#include <SFML/Graphics.hpp>
#include "Location.h"

class Board {			//in charge of drawing the snake game

public:
	Board(const int screenwidth,const int screenheight);
	
	
	void DrawTiles(const Location& loc,const sf::Color& color,sf::RenderWindow& createwindow);
	

	int GetxTilesNum() const;		//gets numver of x tiles
	int GetyTilesNum() const;		//gets number of y tiles
	int GetScreenWidth() const;		//gets the screen width
	int GetScreenHeight() const;	//gets the screen height


private:
	
	sf::RectangleShape drawtile;
	int xTilesNum;					//number of tiles in x axis needed
	int yTilesNum;					//number of tiles in y axis needed
	static constexpr float TileOutlineThickness = 2.0f;	//outline thickness for the tiles.
	static constexpr int TileDimensions = 25;		//dimensions of the square tile
	int screenwidth;
	int screenheight;
	


};