#include "Card_2.h"

Card_2::Card_2(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

void Card_2::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	Ladder* pLadder = pGrid->GetNextLadder(GetPosition());
	if (pLadder==NULL)
		return;
	
	pGrid->GetCurrentPlayer()->MoveToNextladder(pGrid, pLadder);

	
}

Card_2::~Card_2()
{
}
