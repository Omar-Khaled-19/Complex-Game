#include "Card_5.h"

Card_5::Card_5(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}


void Card_5::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 5 : Move the player backward with the same number of steps that he just rolled.");

	CellPosition pos(position.GetCellNum() - pPlayer->GetDiceNum());
	pGrid->UpdatePlayerCell(pPlayer, pos);
}


