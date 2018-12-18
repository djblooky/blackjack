#pragma once
#include "Player.h"
#include <vector>
class Deck
{
private:
	std::vector<Card> m_deck;
public:
	Deck();
	~Deck();
	void createDeck();
	void deal(std::vector<Player> &players);
	void shuffle();
	void hit(Player &player);
};

