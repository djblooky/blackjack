#pragma once
#include "Player.h"
#include "Deck.h"

class Game
{
private:
	Deck m_deck;
	Player m_p1, m_p2, m_p3, m_p4;
	std::vector<Player> m_players;
	bool winner = false;

public:
	Game();
	~Game();
	void gameLoop();
	void displayHands();
	void turn(Player player);
};

