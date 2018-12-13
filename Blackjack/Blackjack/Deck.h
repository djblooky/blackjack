#pragma once
#include "Player.h"
#include <vector>
class Deck
{
private:
	std::vector<Card> m_deck;
	Card m_ace;
public:
	Deck();
	~Deck();
	void createDeck();
	void deal(std::vector<Player> players);
	void hit(Player player);
};

