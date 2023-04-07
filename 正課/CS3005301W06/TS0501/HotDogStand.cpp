/*****************************************************************//**
 * file : HotDogStand.cpp
 * Author : ³¯«Û¾§ 
 * Create date : March 28, 2023
 * Last update : March 28, 2023
 * Description : HotDogStand.cpp
 *********************************************************************/
#include "HotDogStand.h"
#include <cstring> // use the string tool
#include <iostream> 

int HotDogStand::totalSellAmount(0); // initital the total sell amount to 0

/**
 * Intent : create a HotDogStand class
 * pre : none
 * post : none
 */
HotDogStand::HotDogStand()
{
}

/**
 * Intent : create a HotDogStand class with its id
 * pre : need const char pointer id parameter
 * post : create a HotDogStand class and inital its id to the id parameter and set its sell anount to 0 
 * \param id 
 */
HotDogStand::HotDogStand(const char * id)
{
	this->standId = new char[strlen(id) + 1]; // new a space to store the id, and its length is id's length + 1
	std::copy(id, id + strlen(id) + 1, this->standId); // copy the id to the current standId by std::copy function

	this->hotDogSellAmount = 0; // innitial the sell amount to 0
}

/**
 * Intent : create a HotDogStand class with its id and its amount
 * pre : need const char pointer id  parameter and amount
 * post : create a HotDogStand class and inital its id to the id parameter and set its sell anount to the parameter
 * \param id
 * \param amount
 */
HotDogStand::HotDogStand(const char * id, int amount)
{
	this->standId = new char[strlen(id) + 1]; // open a space which size is id's length plus 1
	std::copy(id, id + strlen(id) + 1, this->standId); // use std::copy function to copy the id value to the id

	this->hotDogSellAmount = amount; // initial the current sell amount to be the parameter amount
	totalSellAmount += amount; // let total sell amount value plus amount
}

/**
 * Intent : free the space from the id
 * pre : none
 * post : free the space from the standId 
 */
HotDogStand::~HotDogStand()
{
	delete []this->standId; // delete the space from the standId
}

/**
 * Intent : let the current sell amount + 1
 * pre : none
 * post : let the current sell amount + 1 and let the total sell amount + 1
 */
void HotDogStand::justSold()
{
	this->hotDogSellAmount += 1; // let the current hotSogSellAmount + 1
	totalSellAmount += 1; // total sell amount value + 1
}

/**
 * Intent : print out the stand ID and it's sell amount
 * pre : none
 * post : output the standID and it's hot dog sell amount value
 */
void HotDogStand::print()
{
	// print out the stand ID and it's hotDogSellAmount
	std::cout << this->standId << " " << this->hotDogSellAmount << std::endl;
}

/**
 * Intent : get the hotDogAmount value
 * pre : none 
 * post : return the hotDogAmount value
 * \return 
 */
int HotDogStand::thisStandSoldAmount()
{
	return this->hotDogSellAmount; // return the current sell amount
}

/**
 * Intent : get the all Stand Sold Amount value
 * pre : none
 * post : return the value of all stand sold amount
 * \return 
 */
int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount; // return the current total sell amount
}
