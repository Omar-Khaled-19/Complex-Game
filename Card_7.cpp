#include "Card_7.h"

Card_7::Card_7(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}

void Card_7::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 7 : Restarts the game for the first player whose cell is after the current player in the grid.");

	CellPosition pos(1);

	if (pGrid->GetNearestPlayer(pPlayer))
		pGrid->UpdatePlayerCell(pGrid->GetNearestPlayer(pPlayer), pos);

	else
		pGrid->PrintErrorMessage("Nothing Change");
}
