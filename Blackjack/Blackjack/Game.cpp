#include "pch.h"
#include "Game.h"


Game::Game()
{
	m_p2.setDifficulty(2); //p2 has 1/2 chance to hit (hard AI)
	m_p3.setDifficulty(3); //p3 has 1/3 chance to hit (normal AI)
	m_p4.setDifficulty(4); 	//p3 has 1/4 chance to hit (casual AI)
	m_p1.setName("Player 1");
	m_p2.setName("Player 2");
	m_p3.setName("Player 3");
	m_p4.setName("Player 4");

	m_players.push_back(m_p1);
	m_players.push_back(m_p2);
	m_players.push_back(m_p3);
	m_players.push_back(m_p4);
}


Game::~Game()
{
}

void Game::gameLoop()
{
	m_deck.createDeck();
	m_deck.shuffle();
	while (!winner) { //while no one has won yet

		//all players bet 10 units
		m_deck.deal(m_players);
		displayHands();

		//while no players have 21 and all players havent busted, checkRoundWinner = false and checkRoundBust = false
			// if player hasnt busted, turn
	}
	
}

void Game::displayHands()
{
	for (auto &player : m_players) { //for each player
		player.showHand(player); //show player's hand
	}
}

void Game::turn(Player player)
{
	if (player.getDifficulty() == 1) { //user player
		//user input hit or pass
	}
	else  { // AI
		player.rollHitChance(); 
		if (player.getHitChance() == 0) {
			m_deck.hit(player);
		}
	}
	
	//if player.m_hand.back == ace (11 default) :
		//if player.gethandtotal > 21, m_hand.back = 1

	//if player.getHandTotal() >21, player.setbust = true

}
