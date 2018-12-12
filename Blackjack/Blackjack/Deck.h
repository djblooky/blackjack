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
	void deal(Player p1, Player p2, Player p3, Player p4);
	void hit(Player player);
};

