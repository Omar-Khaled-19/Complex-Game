#pragma once
#include"Card.h"

class Card_11 : public Card
{



public:
	Card_11(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~Card_11();
};

