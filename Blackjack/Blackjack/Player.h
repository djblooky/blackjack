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
	unsigned int m_handTotal;
	unsigned int m_difficulty;
	unsigned int m_hitChance;
	bool bust = false;
public:
	Player();
	int getUnits();
	std::string getName();
	void setName(std::string name);
	int getHitChance();
	void showHand(Player player);
	void tallyHandTotal();
	void addToHand(Card card);
	void rollHitChance();
	void bet(unsigned int units);
	int getHandTotal();
	int getDifficulty();
	void setDifficulty(int difficulty);
};

