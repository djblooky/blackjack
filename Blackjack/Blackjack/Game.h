#pragma once
#include "Player.h"
#include "Deck.h"

class Game
{
private:
	Deck deck;
public:
	Game();
	~Game();
	void gameLoop();
	void turn(Player player);
};

