#pragma once
#include "Card.h"
class Card_2 : public Card
{

public:
	Card_2(const CellPosition& pos); 


	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~Card_2(); 
};

