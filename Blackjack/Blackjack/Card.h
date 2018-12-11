#pragma once
class Card
{
private:
	enum suit {
		Diamond,
		Heart,
		Spade,
		Club
	};

	enum value {Ace,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King};

public:
	Card();
	~Card();
	int drawRandomCard();
};

