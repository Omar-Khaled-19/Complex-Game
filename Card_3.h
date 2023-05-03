#pragma once
#include "Card.h"
class Card_3 : public Card
{

public:
	
	Card_3(const CellPosition& pos); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
};

