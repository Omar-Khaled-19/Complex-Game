#include "Card_3.h"

Card_3::Card_3(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}

void Card_3::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 3 : Gives the player an extra dice roll. ");
}


