#pragma once
#include "Card.h"
class Card_12 : public Card
{

public:
	
	Card_12(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
};

