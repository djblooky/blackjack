#include "pch.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <algorithm>

Game::Game()
{
	m_p2.setDifficulty(2); 
	m_p3.setDifficulty(3); 
	m_p4.setDifficulty(4); 	
	m_p2.setName("Player 2");
	m_p3.setName("Player 3");
	m_p4.setName("Player 4");
	m_p2.setHitTarget(20);
	m_p3.setHitTarget(15);
	m_p4.setHitTarget(10);

	m_players.push_back(m_p1);
	m_players.push_back(m_p2);
	m_players.push_back(m_p3);
	m_players.push_back(m_p4);
}

void Game::gameLoop()
{
	beginGame();
	while (!m_winner) { //while no one has won the game yet
		m_deck.deal(m_players); //deal 2 cards to each player
		//displayStats(false);
		placeBets(10); //each player bets 10 units
		Sleep(2000);
		while (!m_roundwinner) { //no one has won the round yet
			std::cout << "\n\tRound " << m_round << " | Winnings pot: " << m_unitPot << std::endl << "\t----------------" << std::endl;
			displayStats(false); //show players' units and hands
			naturalCheck(); //check for natural 21
			if (m_roundwinner == true) { //
				awardPot();
				m_round++;
				break;
			}
			else {
				Sleep(3000);
				playTurns(); //add math for aces to turn method!

				displayStats(true); //reveal all hands
				assignRoundWinner();
				m_round++;
				break;
			}
		}
		Sleep(3000);
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
	m_roundwinner = false;
}

void Game::assignRoundWinner()
{
	std::vector<int> scores;

	for (auto &player : m_players) {
		if (player.getBust() == false) {
			player.tallyHandTotal();
			scores.push_back(player.getHandTotal()); //add hand total to vector scores
		}
	}	

	sort(scores.begin(), scores.end()); //sorts lowest to highest scores
	int winScore = scores.back(); //last (highest) score is winning score

	for (auto &player : m_players) {
		if (player.getHandTotal() == winScore) { //if player has winning score
			player.setRoundWon(true); //set player to winner
		}
	}

	awardPot();
}

void Game::bustCheck(Player &player) //sees if any player has busted
{
		player.tallyHandTotal(); //add up all card values in each hand
		if (player.getHandTotal() > 21) {
			std::cout << "\n\t" << player.getName() << " has busted!" << std::endl;
			player.setBust(true);
		}
}
 
void Game::naturalCheck()
{	
	if (m_round == 1) {
		for(auto &player: m_players){
			player.tallyHandTotal();
			if (player.getHandTotal() == 21) {
				std::cout << "\n\t" << player.getName() << " has a blackjack!" << std::endl;
				m_roundwinner = true;
				player.setRoundWon(true); //assign player as a winner
			}	
		}	
	}
}

void Game::awardPot()
{
	std::vector<Player> winners;
	unsigned int winnerCount = 0;
	unsigned int award;

	for (auto &player : m_players) {
		if (player.getRoundWon() == true) { //if player is a winner
			winners.push_back(player); //add player to winners vector
			winnerCount++;
		}
	}

	award = m_unitPot / winnerCount; //award each winner even amount of units
	m_unitPot = 0; //pot is empty

	

	for (auto &winner : winners) { //give each winner the award
		std::cout << "\n\tWinner " << winner.getName() << " is awarded " << award << " units!" << std::endl;
		winner.addUnits(award);
		winner.setRoundWon(false); //player is no longer a winner
	}

	//winner announcement
	resetRound();
}

void Game::turn(Player &player)
{
	player.tallyHandTotal();

	// ON USER TURN
	if (player.getDifficulty() == 1) { 
		int choice = 0;
		while (choice != 2 && player.getBust() == false) {
			std::cout << "\n\t" << "1. Hit or 2. stand?" << std::endl;
			std::cin >> choice;
			if (choice == 1) {
				m_deck.hit(player);
				std::cout << "\t" << player.getName() << " hits!" << std::endl;
				player.showHand();
				player.tallyHandTotal();
				bustCheck(player);
			}
		}
		if(choice == 2)
			std::cout << "\t" << player.getName() << " stands!" << std::endl;
	}

	// ON ROBOT TURN
	else { 
		if (player.getHitTarget() > player.getHandTotal()) { //if robot hasnt reached its target hand
			m_deck.hit(player);
			std::cout << "\t" << player.getName() << " hits!" << std::endl;
			player.tallyHandTotal();
			bustCheck(player);
		}
		else{
			std::cout << "\t" << player.getName() << " stands!" << std::endl;
		}
	}

	checkIfOut(player); //checks if player still has units
}

void Game::placeBets(unsigned int units)
{
	std::cout << "\n\tAll players bet " << units << " units to start!" << std::endl;

	for (auto &player : m_players) { 
		player.bet(units);
		addToPot(units);
	}
}

void Game::playTurns()
{
	for (auto &player : m_players) {
		if (player.getBust() == false) { //if not busted
			std::cout << "\n\t" << player.getName() << "'s turn!" << std::endl;
			Sleep(2000);
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

void Game::displayStats(bool reveal)
{
	std::cout << std::endl;
	for (auto &player : m_players) { //for each player
		if (reveal == true || player.getBust() == true) {
			player.revealHand(); 
		}
		else {
			player.showHand(); //show player's hand
		}
		
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
