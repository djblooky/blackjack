#include "pch.h"
#include "Player.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <ctime>
#include <random>

Player::Player()
{
	m_units = 200;
	m_difficulty = 1;
}

void Player::showHand()
{
	std::cout << "\t" << m_name << "'s hand: ";
	if (m_difficulty == 1) { //if player 1, show entire hand
		for (auto &card : m_hand) {
			std::cout << card.getName() << " ";
		}
		tallyHandTotal();
		std::cout << "(" << m_handTotal << ")";
	}
	else if (m_difficulty > 1) {
		int i = 0;
		for (auto &card : m_hand) {
			if (i == 0) {
				std::cout << "[x]" << " ";
			}
			else {
				std::cout << card.getName() << " ";
			}
			i++;
		}
	}
	
	std::cout << std::endl;
}

void Player::revealHand()
{
	std::cout << "\t" << m_name << "'s hand: ";
		for (auto &card : m_hand) {
			std::cout << card.getName() << " ";
		}
	
	tallyHandTotal();
	std::cout <<"("<< m_handTotal << ")" << std::endl;
}

void Player::clearHand() 
{
	m_hand.clear();
}

void Player::tallyHandTotal() //adds up cards in current hand
{
	int aceCount = 0;
	bool changeAce = false;

	//aces value are 11 by default. this will change it to 1 if possible to avoid a bust
	do {
		m_handTotal = 0;
		if (aceCount > 0) { //if there's at least 1 ace, and a bust could be prevented
			changeAce = true; //the ace's default val should be changed
		}
		for (auto &card : m_hand) { //for each card in hand
			if (card.getValue() == 11) { //is there an ace that hasnt been changed
				if (changeAce) { //if it needs to be changed to avoid bust
					card.setValue(1); //change ace val
					changeAce = false; //only change 1 ace at a time and check if busts each time
				}
				else 
				{
					aceCount++; //count aces on first loop
				}
			}
			m_handTotal += card.getValue();
		}
	} while (m_handTotal > 21 && aceCount > 0); //if busted and theres an ace, recount
	
}

void Player::addToHand(Card card)
{
	m_hand.push_back(card);
}

void Player::bet(unsigned int units)
{
	Game game;
	if (m_units >= units) { //if player has the funds for the bet
		m_units -= units;
	}
	else if (m_units > 0) { //if not, does the player have money

	}
	else {
		game.checkIfOut(*this); //check if player has 0 units
	}
}

//getters and setters
int Player::getHandTotal() { return m_handTotal; }
int Player::getDifficulty(){return m_difficulty;}
void Player::setDifficulty(int difficulty) { m_difficulty = difficulty; }
int Player::getUnits() { return m_units; }
void Player::addUnits(unsigned int units) { m_units += units; }
std::string Player::getName() { return m_name; }
void Player::setName(std::string name){	m_name = name;}
bool Player::getBust() { return m_bust; }
void Player::setBust(bool bust) { m_bust = bust; }
bool Player::getRoundWon() { return m_roundWon; }
void Player::setRoundWon(bool won) { m_roundWon = won; }
void Player::setHitTarget(unsigned int target) { m_hitTarget = target; }
int Player::getHitTarget() { return m_hitTarget; }
