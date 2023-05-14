#pragma once
#include "Card.h"

class Card_6 : public Card
{
	int cellNum;

public:
	
	Card_6(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	void transfereCardParameters(Card* pCard);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
};

