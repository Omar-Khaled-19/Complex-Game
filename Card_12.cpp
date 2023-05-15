#include "Card_12.h"
#include "Card_9.h"
#include "Card_10.h"
#include "Card_11.h"

Card_12::Card_12(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12;
}


void Card_12::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 12: Moves the ownership of the most expensive station to the poorest player. ");

	if (pGrid->HighestFees(pPlayer) == 9)
	{
		pGrid->MoveOwnership(pPlayer, 9);
		pGrid->PrintErrorMessage("Now the owner of card 9 will be player " + to_string(Card_9::owner));
	}

	if (pGrid->HighestFees(pPlayer) == 10)
	{
		pGrid->MoveOwnership(pPlayer, 10);
		pGrid->PrintErrorMessage("Now the owner of card 10 will be player " + to_string(Card_10::owner));
	}

	if (pGrid->HighestFees(pPlayer) == 11)
	{
		pGrid->MoveOwnership(pPlayer, 11);
		pGrid->PrintErrorMessage("Now the owner of card 11 will be player " + to_string(Card_11::owner));
	}
}

