#pragma once
#include "Card.h"
class Card_3 : public Card
{
private:


public:
	Card_3(const CellPosition& pos); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~Card_3(); 
};

