#include "pch.h"
#include "Deck.h"


Deck::Deck()
{
	
}

Deck::~Deck()
{
}

void Deck::createDeck() //adds 4 cards of each value to 52 card deck
{
	Card ace("Ace", 11);
	Card two("Two", 2);
	Card three("Three", 3);
	Card four("Four", 4);
	Card five("Five", 5);
	Card six("Six", 6);
	Card seven("Seven", 7);
	Card eight("Eight", 8);
	Card nine("Nine", 9);
	Card ten("Ten", 10);
	Card jack("Jack", 10);
	Card queen("Queen", 10);
	Card king("King", 10);

	for (int i = 0; i < 4; i++) { //push four of each card to the deck
		m_deck.push_back(ace);
		m_deck.push_back(two);
		m_deck.push_back(three);
		m_deck.push_back(four);
		m_deck.push_back(five);
		m_deck.push_back(six);
		m_deck.push_back(seven);
		m_deck.push_back(eight);
		m_deck.push_back(nine);
		m_deck.push_back(ten);
		m_deck.push_back(jack);
		m_deck.push_back(queen);
		m_deck.push_back(king);
	}
	
}

void Deck::deal(std::vector<Player> players) //gives one card to each player 
{
	for (auto &player : players) { //for each player in players
		hit(player);
	}
}

void Deck::hit(Player player) //gives 1 card to player
{
	//get random card from m_deck
	//remove card from m_deck
	//add card to player.m_hand
}


