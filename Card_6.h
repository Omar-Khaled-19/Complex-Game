#pragma once
#include "Card.h"

class Card_6 : public Card
{
	int cellNum;

public:
	
	Card_6(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	void transfereCardParameters(Card* pCard);

	virtual void Save(ofstream& OutFile, int type);

	virtual void Load(ifstream& Infile);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
};

