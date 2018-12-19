#pragma once
#include <string>
#include <random>
#include "Card.h"
class Player
{
private:
	unsigned int m_units;
	std::string m_name;
	std::vector<Card> m_hand;
	unsigned int m_handTotal = 0;
	unsigned int m_difficulty;
	unsigned int m_hitChance;
	bool m_bust = false;
	bool m_roundWon = false;
public:
	Player();
	int getUnits();
	void addUnits(unsigned int units);
	std::string getName();
	void setName(std::string name);
	int getHitChance();
	bool getBust();
	void setBust(bool bust);
	bool getRoundWon();
	void setRoundWon(bool won);
	void showHand(Player player);
	void clearHand();
	void tallyHandTotal();
	void addToHand(Card card);
	void rollHitChance();
	void bet(unsigned int units);
	int getHandTotal();
	int getDifficulty();
	void setDifficulty(int difficulty);
};

