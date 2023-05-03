#pragma once
#include "Card.h"
class Card_7 : public Card
{
public:
	Card_7(const CellPosition &pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
};

