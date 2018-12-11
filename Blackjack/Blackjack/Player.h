#pragma once
#include <string>
#include <vector>
class Player
{
private:
	int m_units = 200;
	std::string m_name;
	std::vector<int> m_hand;
public:
	Player(std::string name);
	~Player();
	int getUnits();
	std::string getName();
	void showHand();
};

