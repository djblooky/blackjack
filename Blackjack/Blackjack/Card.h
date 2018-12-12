#pragma once
class Card
{
public:
	Card();
	~Card();
	int drawRandomCard();

	enum suit {Diamond,Heart,Spade,Club};
	enum value { Ace, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
};

