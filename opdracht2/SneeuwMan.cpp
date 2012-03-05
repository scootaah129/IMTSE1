/*
 * SneeuwMan.cpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Michael
 */


#include "SneeuwMan.hpp"

//constructor
SneeuwMan::SneeuwMan(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
}


void SneeuwMan::move(int direction)
{
	this->positionX += direction;
}

void SneeuwMan::draw()
{
	maSetColor(0xDFDFDF);

	//onderste rechthoek
	maFillRect(this->positionX, this->positionY, 30, 50);

	//onderste rechthoek
	maFillRect(this->positionX + 5, this->positionY - 30, 20, 30);
}
