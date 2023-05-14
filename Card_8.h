#pragma once
#include "Card.h"
class Card_8 : public Card
{
	int amount;

public:
	Card_8(const CellPosition& pos) ;

	virtual void ReadCardParameters(Grid* pGrid);

	void transfereCardParameters(Card* pCard);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
};

