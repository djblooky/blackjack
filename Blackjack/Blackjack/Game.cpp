#include "pch.h"
#include "Game.h"


Game::Game()
{
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
	m_deck.shuffle();
	m_deck.deal(m_players); 
}

void Game::turn(Player player)
{

}
