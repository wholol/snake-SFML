#pragma once


struct Location {
	int x;
	int y;

	Location& operator +=(const Location& other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}

	bool operator ==(const Location& other) const{		//const. ensures x and y arent changed
		return (x == other.x && y == other.y);
	}

};