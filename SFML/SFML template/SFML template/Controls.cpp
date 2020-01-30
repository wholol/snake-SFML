#include "Controls.h"

void Controls::DetermineDirection(const std::string& direction,Snake& snake)
{
	if (direction == "up") {
		if (snake.checkReverse({ 0 , -1 })) {		//if snake is going in reverse
			//do nothing
		}

		else {
			ControlsLoc = { 0 , -1 };
		}
		
	}

	if (direction == "down") {
		if (snake.checkReverse({ 0 , 1 })) {

		}
		else {
			ControlsLoc = { 0 , 1 };
		}
		
	}

	if (direction == "left") {
		if (snake.checkReverse({ -1 , 0 })) {

		}
		else {
			ControlsLoc = { -1 , 0 };
		}
		
	}

	if (direction == "right") {
		if (snake.checkReverse({ 1 , 0 })) {

		}
		else{
			ControlsLoc = { 1 , 0 };
		}
		
	}

}

Location Controls::GetDirectionVector() const
{
	return ControlsLoc;
}
