#pragma once
#include "PLayer.h"
class Deck
{
public:
	Deck();
	~Deck();
	void deal(Player p1, Player p2, Player p3, Player p4);
	void hit();
};
