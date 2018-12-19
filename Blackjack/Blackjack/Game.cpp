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
	while (!m_winner) { //while no one has won the game yet
		m_roundwinner = false;
		m_deck.deal(m_players); //deal 2 cards to each player
		placeBets(10); //each player bets 10 units
		naturalCheck(); //check for natural 21
		while (!m_roundwinner) { //no one has won the round yet
			displayStats(); //show players' units and hands
			Sleep(3000);
			playTurns(); //add math for aces to turn method!
			bustCheck();

			//if last player standing, assign winner
			checkIfRoundWon();
		}
		resetRound();
	}
}

void Game::resetRound()
{
	for (auto &player : m_players) {
		player.setBust(false);
		player.clearHand();
	}
	
	m_deck.emptyDeck();
	m_deck.createDeck();
	m_deck.shuffle();
}

void Game::checkIfRoundWon()
{
	if (m_roundwinner == true) {
		awardPot();	//check for winners and award money
	}
}

void Game::bustCheck() //sees if any player has busted
{
	for (auto &player : m_players) {
		player.tallyHandTotal(); //add up all card values in each hand
		if (player.getHandTotal() > 21) {
		std::cout << "\n\t" << player.getName() << " has busted!" << std::endl;
		player.setBust(true);
		}
	}
	
}
 
void Game::naturalCheck()
{	
	for(auto &player: m_players){
		player.tallyHandTotal();
		if (player.getHandTotal() == 21) {
			std::cout << "\n\t" << player.getName() << " has a blackjack!" << std::endl;
			m_roundwinner = true;
			player.setRoundWon(true); //assign player as a winner
		}	
	}

	checkIfRoundWon();
}

void Game::awardPot()
{
	std::vector<Player> winners;
	unsigned int winnerCount = 0;

	for (auto &player : m_players) {
		if (player.getRoundWon() == true) { //if player is a winner
			winners.push_back(player); //add player to winners vector
			winnerCount++;
		}
	}

	unsigned int award = m_unitPot / winnerCount; //award each winner even amount of units
	m_unitPot = 0; //pot is empty

	for (auto &winner : winners) { //give each winner the award
		winner.addUnits(award);
		winner.setRoundWon(false); //player is no longer a winner
	}
}

void Game::turn(Player &player)
{
	std::cout << "\n\t" << player.getName() << "'s turn!" << std::endl;
	Sleep(1000);

	// ON USER TURN
	if (player.getDifficulty() == 1) { 
		int choice;
		std::cout << "\n\t" << "1. Hit or 2. stand?" << std::endl;
		std::cin >> choice;
		if (choice == 1) {
			m_deck.hit(player);
			std::cout << "\t" << player.getName() << " hits!" << std::endl;
		}
		else {
			std::cout << "\t" << player.getName() << " stands!" << std::endl;
		}

	}

	// ON ROBOT TURN
	else { 
		player.rollHitChance();  //depending on bot, will calculate dif chance to hit or pass
		if (player.getHitChance() == 0) {
			m_deck.hit(player);
			std::cout << "\t" << player.getName() << " hits!" << std::endl;
		}
		else{
			std::cout << "\t" << player.getName() << " stands!" << std::endl;
		}
	}

	//if player.m_hand.back == ace (11 default) :
		//if player.gethandtotal > 21, m_hand.back = 1

	//if player.getHandTotal() >21, player.setbust = true

	checkIfOut(player); //checks if player still has units

}

void Game::placeBets(unsigned int units)
{
	for (auto &player : m_players) { 
		player.bet(units);
	}
}

void Game::playTurns()
{
	for (auto &player : m_players) {
		if (player.getBust() == false) { //if not busted
			turn(player);
		}
	}
}

void Game::beginGame()
{
	std::cout << "\n\tWelcome to BlackJack, enter your name player: ";
	std::string name;
	std::cin >> name;
	m_p1.setName(name);
	m_players[0] = m_p1; //update player's name in the players vector

	m_deck.createDeck(); //creates and adds cards to deck
	m_deck.shuffle();

}

void Game::displayStats()
{
	std::cout << std::endl;
	for (auto &player : m_players) { //for each player
		player.showHand(player); //show player's hand
		if (player.getBust() == true) {
			std::cout << "\t" << "Busted!";
		}
		std::cout << "\t" << player.getUnits() << " units" << std::endl;
	}
}

void Game::checkIfOut(Player player)
{
	if (player.getUnits() <= 0) { //if player is out of money
		std::cout << "\n\t" << player.getName() << " has run out of units and is out of the game!" << std::endl;
		removePlayer(player); //remove player from players vector
	}
}

void Game::removePlayer(Player &player) //removes player from game (m_players vector) 
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
