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
	// de x en y positie die binnenkomen wanneer een nieuwe sneeuwvlok wordt gemaakt worden aan de x en y positie toegekend
	this->positionX = positionX;
	this->positionY = positionY;
	// de grootte van de sneeuwman is een willekeurig getal met max grootte 8 pixels
	size = rand() % 8;
}

void SneeuwVlok::draw()
{
	// witte kleur
	maSetColor(0xFFFFFF);
	// het vierkantje van de sneeuw
	maFillRect(this->positionX, this->positionY, this->size, this->size);
}

void SneeuwVlok::fall(int groundLevel)
{
	// een if waarmee gecontroleerd word of de sneeuwvlok de grond heeft geraakt of niet
	if(this->positionY <= groundLevel)
	{
		// nog niet de grond geraakt dan krijgt de Y positie een waarde erbij, in dit geval zijn eigen grote(grote sneeuwvlokkenvaller sneller)
		this->positionY += size;

		//update het scherm
		maUpdateScreen();

		// als de sneeuwvlok de grond niet heeft geraakt is de boolean false, als de boolean true is
		this->dead = false;
	}
	else
	{
		// als de sneeuwvlok de grond heeft geraakt dan word de boolean true en is die ''dead''
		this->dead = true;
	}
}

bool SneeuwVlok::isDead()
{
	// geeft de waarde van de boolean dead terug
	return this->dead;
}

