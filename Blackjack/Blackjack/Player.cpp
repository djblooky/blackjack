#include "pch.h"
#include "Player.h"
#include <string>
#include <iostream>

Player::Player()
{
	m_units = 100;
}


Player::~Player()
{
}

void Player::showHand()
{
	for (auto &card : m_hand) {
		std::cout << &card << "\t";
	}
		
}

void Player::tallyHandTotal() //adds up cards in current hand
{
	for (auto &card : m_hand) {
		m_handTotal += card.getValue();
	}
}

void Player::addToHand(Card card)
{
	m_hand.push_back(card);
}

int Player::getHandTotal() { return m_handTotal; }
int Player::getUnits() { return m_units; }
std::string Player::getName() { return m_name; }
void Player::setName(std::string name){	m_name = name;}
