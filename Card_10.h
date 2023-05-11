#pragma once
#include"Card.h"

class Card_10 : public Card
{



public:
	Card_10(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~Card_10();
};

