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
	// de x en y positie die binnenkomen wanneer een nieuwe sneeuwman wordt gemaakt worden aan de x en y positie toegekend
	this->positionX = positionX;
	this->positionY = positionY;
}


void SneeuwMan::move(int direction)
{
	// mocht er een verplaatsing plaatsvinden van krijgt de X een grotere(naar rechts) of kleinere waarde(naar links)
	this->positionX += direction;
}

void SneeuwMan::draw()
{
	// een grijze kleur
	maSetColor(0xDFDFDF);

	//onderste rechthoek
	maFillRect(this->positionX, this->positionY - 40, 30, 40);

	//onderste rechthoek
	maFillRect(this->positionX + 5, this->positionY - 70, 20, 30);
}
