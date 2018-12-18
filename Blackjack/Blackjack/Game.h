#pragma once
#include "Player.h"
#include "Deck.h"

class Game
{
private:
	Deck m_deck;
	Player m_p1, m_p2, m_p3, m_p4;
	std::vector<Player> m_players;
	bool m_winner = false;
	bool m_roundwinner = false;
	unsigned int m_unitPot = 0;
public:
	Game();
	void gameLoop();
	void placeBets(unsigned int units);
	void playTurns();
	void beginGame();
	void displayStats();
	void turn(Player &player);
	void checkIfOut(Player player);
	void removePlayer(Player &player);
	void addToPot(unsigned int units);
};

