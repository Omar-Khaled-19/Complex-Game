#include "Card_4.h"

Card_4::Card_4(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

void Card_4::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 4 : Prevents the player from rolling the next turn.");
	
	pPlayer->SetCard_4(true);
}
