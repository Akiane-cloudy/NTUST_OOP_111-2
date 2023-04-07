#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"


//************************************************************
// Trigger Class
//************************************************************
class Trigger {
	// Implement Trigger Class
	/*Please implement your code here*/
private:
	Position triggerPosition; // use Position struct to store the current position
	int experience; // represent the how much experience will the trigger give
	char triggerIcon; // the trigger's icon

public:
	// intent: a constructor to initial the x and y and exp to the parameter
	// pre: none
	// pose: modify this position to the input position and initial the icon
	Trigger(int x,int y, int exp)
	{
		this->triggerPosition.x = x; // modify the current position the the parameter
		this->triggerPosition.y = y; // modify the current position the the parameter
		this->experience = exp; // modify the experience with the exp
		this->triggerIcon = 'T'; // change the icon to 'T'
	}

	// intent: get the current position
	// pre: none
	// post: none
	// return: return the current position
	Position getPos()
	{
		return this->triggerPosition; // return the current position
	}

	// intent: get the trigger's icon
	// pre: none
	// post: none
	// return: return the trigger's icon
	char getIcon()
	{
		return this->triggerIcon; // return the trigger's icon
	}

	// intent: get the experience of trigger
	// pre: none
	// post: none
	// return: return the trigger's experience
	int getExpAmount()
	{
		return this->experience; // return the trigger's experience
	}

	// intent: check if the hero touch the trigger and update the hero's experience
	// pre: none
	// post: modify the hero's experience and it's level
	void update(Hero& hero)
	{
		// if the hero's position is equal to the trigger's position then let hero het the experience
		if (hero.getPos().x == triggerPosition.x &&
			hero.getPos().y == triggerPosition.y)
		{
			hero.gainEXP(this->experience); // call the gainEXP function to let hero get the experience
		}
	}
	/************************************************************************/
};

