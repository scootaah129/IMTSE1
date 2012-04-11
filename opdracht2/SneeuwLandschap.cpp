/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#include "SneeuwLandschap.hpp"


//globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;


//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );

	//stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte = 30;

	//maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan( screenWidth / 2, screenHeight - this->sneeuwHoogte );
}


//wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{
	//als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		//pak de key code
		int key = maGetKeys();

		//kijk voor linkertoets
		if( key == MAKB_LEFT )
			this->sneeuwMan->move( -6 );	//beweeg sneeuwman -6 pixels

		//kijk voor rechtertoets
		if( key == MAKB_RIGHT )
			this->sneeuwMan->move( 6 );		//beweeg sneeuwman 6 pixels
	}


	//TODO: maakt een nieuwe sneeuwvlok
	SneeuwVlok* sneeuwVlokje = new SneeuwVlok( (rand()%screenWidth), 0);

	// voeg een sneeuwvlok toe aan de ''arraylist''
	this->sneeuwVlokArray.add(sneeuwVlokje);

	//TODO: laat alle sneeuwvlokken vallen doormiddel van een for loop
	for(int i = 0; i < this->sneeuwVlokArray.size(); i++)
	{
		this->sneeuwVlokArray[i]->fall(screenHeight-sneeuwHoogte);
	}
}


//wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	//kleur de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	//TODO: teken de sneeuwman
	this->sneeuwMan->draw();

	//TODO: teken alle sneeuwvlokken doorm iddel van een for loop
	for(int i = 0; i < this->sneeuwVlokArray.size(); i++)
	{
		this->sneeuwVlokArray[i]->draw();
	}

	// omt e zorgen dat de applicatie niet crashed worden de sneeuwvlokken verwijderd, ook worden de sneeuwvlokken uit de "array lists"
	for(int i = 0; i < this->sneeuwVlokArray.size(); i++)
	{
		if(sneeuwVlokArray[i]->isDead())
		{
			delete sneeuwVlokArray[i];
			this->sneeuwVlokArray.remove(i);
		}
	}

	// update het scherm mochten er veranderingen zijn
	maUpdateScreen();

}


