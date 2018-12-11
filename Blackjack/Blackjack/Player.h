#pragma once
#include <string>
#include <vector>
class Player
{
private:
	int m_units = 200;
	std::string m_name;
	std::vector<int> m_hand;
	int m_handTotal;
public:
	Player(std::string name);
	~Player();
	int getUnits();
	std::string getName();
	void showHand();
	void tallyHandTotal();
	int getHandTotal();
};

