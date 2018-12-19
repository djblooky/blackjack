#pragma once
#include "Player.h"
#include <vector>
class Deck
{
private:
	std::vector<Card> m_deck;
public:
	void createDeck();
	void emptyDeck();
	void deal(std::vector<Player> &players);
	void shuffle();
	void hit(Player &player);
};

