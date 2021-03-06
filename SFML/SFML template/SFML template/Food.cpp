#include "Food.h"
#pragma once

Food::Food(const Board& board)
	:Xpos(1, board.GetxTilesNum() - 2),
	Ypos(1, board.GetyTilesNum() - 2),
	rng(std::random_device ()())
{
	xloc = Xpos(rng);
	yloc = Ypos(rng);
	FoodLoc = { xloc, yloc };
}

void Food::respawn(Snake& snake)
{
	do {
		xloc = Xpos(rng);
		yloc = Ypos(rng);
		FoodLoc = { xloc , yloc };
	} while (snake.PreventFoodSpawnInBody(FoodLoc) || FoodLoc == snake.getHeadLocation());
}


bool Food::isEaten(const Snake& snake)
{

	if (snake.getHeadLocation() == FoodLoc) {
		sound.openFromFile("EatenSound.wav");
		sound.play();
		return true;
	}
	else return false;
}

void Food::DrawFood(Board& board, sf::RenderWindow& createwindow)
{
	board.DrawTiles(FoodLoc, sf::Color::Red, createwindow);
}

Location Food::GetFoodLoc() const
{
	return FoodLoc;
}
