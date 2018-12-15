#pragma once
#include <iostream>

class Card
{
private:
	int m_value;
	std::string m_name;
public:
	Card(std::string name, int value);
	Card();

	int getValue();
	void setValue(int value);
	std::string getName();

};

