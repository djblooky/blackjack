#include "pch.h"
#include "Player.h"
#include <string>
#include <iostream>

Player::Player(std::string name)
{
	m_name = name;
}


Player::~Player()
{
}

void Player::showHand()
{
	for (std::vector<Card>::const_iterator i = m_hand.begin(); i != m_hand.end(); ++i) { //iterates through vector
		std::cout << *i << ' ';
	}
		
}

void Player::tallyHandTotal() //adds up cards in current hand
{
}

int Player::getHandTotal() { return m_handTotal; }
int Player::getUnits() { return m_units; }
std::string Player::getName() { return m_name; }
