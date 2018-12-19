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
	unsigned int m_round = 1;
public:
	Game();
	void gameLoop();
	void resetRound();
	void assignRoundWinner();
	void bustCheck(Player & player);
	void naturalCheck();
	void awardPot();
	void placeBets(unsigned int units);
	void playTurns();
	void beginGame();
	void displayStats(bool reveal);
	void turn(Player &player);
	void checkIfOut(Player player);
	void removePlayer(Player &player);
	void addToPot(unsigned int units);
};

