#include "pch.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <ctime>
#include <random>

Player::Player()
{
	m_units = 200;
	m_difficulty = 1;

	
}

void Player::showHand(Player player)
{
	std::cout << player.getName() << "'s hand: ";
	for (auto &card : m_hand) {
		std::cout << &card.getName() << " ";
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

void Player::rollHitChance() //calculates value to hit or pass
{
	srand(time(NULL));
	m_hitChance = rand() % m_difficulty; //if d=1 roll 0-1, d=2 roll 0-2, d=3 roll 0-3;

}

int Player::getHandTotal() { return m_handTotal; }
int Player::getDifficulty(){return m_difficulty;}
void Player::setDifficulty(int difficulty) { m_difficulty = difficulty; }
int Player::getUnits() { return m_units; }
std::string Player::getName() { return m_name; }
void Player::setName(std::string name){	m_name = name;}
int Player::getHitChance() { return m_hitChance; }
