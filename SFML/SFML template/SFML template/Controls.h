#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "Location.h"
#include "Snake.h"

class Controls {

public:
	void DetermineDirection(const std::string& direction,Snake& snake);
	Location GetDirectionVector() const;



private:
	Location ControlsLoc;
	


};