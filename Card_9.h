#pragma once
#include"Card.h"
class Card_9 : public Card
{

public:
	static int price;
	static int fees;
	static bool added;
	static bool bought;
	static int owner;
	static bool saved;
	static bool opened;
	Card_9(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	void transfereCardParameters(Card* pCard);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, int type);

	virtual void Load(ifstream& Infile);

	virtual ~Card_9();

};

