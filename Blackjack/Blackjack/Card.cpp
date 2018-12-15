#include "pch.h"
#include "Card.h"
#include <random>


Card::Card(std::string name, int value)
{
	m_name = name;
	m_value = value;
}

Card::Card()
{

}




int Card::getValue()
{
	return m_value;
}

void Card::setValue(int value)
{
	m_value = value;
}

std::string Card::getName()
{
	return m_name;
}

