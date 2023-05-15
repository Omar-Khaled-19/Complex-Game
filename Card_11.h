#pragma once
#include"Card.h"

class Card_11 : public Card
{

	int  price;
	int  fees;

public:
	Card_11(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	void transfereCardParameters(Card* pCard);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~Card_11();
};

