/*
 * SneeuwVlok.cpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Michael
 */


#include "SneeuwVlok.hpp"

//constructor
SneeuwVlok::SneeuwVlok(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
	size = rand() % 8;
}

void SneeuwVlok::draw()
{
	maSetColor(0xFFFFFF);
	maFillRect(this->positionX, this->positionY, this->size, this->size);
}

void SneeuwVlok::fall(int groundLevel)
{
	if(this->positionY <= groundLevel)
	{
		this->positionY += size;
		maUpdateScreen();
		this->dead = false;
	}
	else
	{
		this->dead = true;
	}
}

bool SneeuwVlok::isDead()
{
	return this->dead;
}

