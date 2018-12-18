#include "pch.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <algorithm>

Game::Game()
{
	m_p2.setDifficulty(2); //p2 has 1/2 chance to hit (hard AI)
	m_p3.setDifficulty(3); //p3 has 1/3 chance to hit (normal AI)
	m_p4.setDifficulty(4); 	//p3 has 1/4 chance to hit (casual AI)
	m_p2.setName("Player 2");
	m_p3.setName("Player 3");
	m_p4.setName("Player 4");

	m_players.push_back(m_p1);
	m_players.push_back(m_p2);
	m_players.push_back(m_p3);
	m_players.push_back(m_p4);
}

void Game::gameLoop()
{
	beginGame();
	while (!m_winner) { //while no one has won yet
		
		m_deck.deal(m_players); //deal 2 cards to each player
		
		while (!m_roundwinner) { 
			Sleep(1000);
			placeBets(10); //each player bets 10 units
			displayStats(); //show players' units and hands
			
			
		}

		
		//while no players have 21 and all players havent busted, checkRoundWinner = false and checkRoundBust = false
			// if player hasnt busted, turn

		//if last player standing roundwinner = true
		//
	}
	
}

void Game::placeBets(unsigned int units)
{
	for (auto &player : m_players) { 
		player.bet(units);
	}
}

void Game::beginGame()
{
	std::cout << "\n\tWelcome to BlackJack, enter your name player: ";
	std::string name;
	std::cin >> name;
	m_p1.setName(name);
	m_players[0] = m_p1;

	m_deck.createDeck(); //creates and adds cards to deck
	m_deck.shuffle();

}

void Game::displayStats()
{
	for (auto &player : m_players) { //for each player
		player.showHand(player); //show player's hand
		std::cout << "\t" << player.getUnits() << " units" << std::endl;
	}
}

void Game::turn(Player &player)
{
	std::cout <<"\n\t" << player.getName() << "'s turn!";

	if (player.getDifficulty() == 1) { //user player
		//user input hit or pass
	}
	else  { // AI
		player.rollHitChance();  //depending on bot, will calculate dif chance to hit or pass
		if (player.getHitChance() == 0) {
			m_deck.hit(player);
		}
	}
	
	//if player.m_hand.back == ace (11 default) :
		//if player.gethandtotal > 21, m_hand.back = 1

	//if player.getHandTotal() >21, player.setbust = true

	checkIfOut(player); //checks if player still has units

}

void Game::checkIfOut(Player player)
{
	if (player.getUnits() <= 0) { //if player is out of money
		std::cout << "\n\t" << player.getName() << " has run out of units and is out of the game!" << std::endl;
		removePlayer(player); //remove player from players vector
	}
}



void Game::removePlayer(Player &player)
{
	int i = 0; // index 0
	for (auto &p : m_players) //go through m_players 
	{
		i++;
		if (p.getDifficulty() == player.getDifficulty()) //until it finds the one passed in
		{
			break;
		}
	}

	m_players.erase(m_players.begin() + i); //erase the player at that index
}

void Game::addToPot(unsigned int units) { m_unitPot += units; }
