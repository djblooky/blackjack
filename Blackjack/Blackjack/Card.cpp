#include "pch.h"
#include "Card.h"
#include <random>


Card::Card()
{
}


Card::~Card()
{
}

int Card::drawRandomCard()
{
	value cardVal; //get random enum value

	switch (cardVal) {
		case Jack || Queen || King: return 10;
			break;
		case Ace: return 11;
			break;
		default: return cardVal;
				break;
	}

	
}
