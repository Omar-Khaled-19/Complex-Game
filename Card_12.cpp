#include "Card_12.h"

Card_12::Card_12(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12;
}


void Card_12::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 12: ");

}

