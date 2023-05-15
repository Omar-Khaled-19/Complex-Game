#include "Card_11.h"
Card_11::Card_11(const CellPosition& pos) : Card(pos)
{
	cardNumber = 11;
}

void Card_11::ReadCardParameters(Grid* pGrid)
{

	bool once = true;
	while (once)
	{
		pGrid->PrintErrorMessage("The amount of coins needed to buy all cells containing this card no. : ");
		price = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		pGrid->PrintErrorMessage("The amount of coins needed to be paid by other players passing this card : ");
		fees = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		pGrid->GetOutput()->ClearStatusBar();
		once = false;
	}
}

void Card_11::transfereCardParameters(Card* pCard)
{
}

void Card_11::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pGrid->PrintErrorMessage("Please enter 1 if you'll buy all cells containing this card no. or 0 if you'll not");
	bool buy = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	if (buy)
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - price);



	}
}

Card_11 :: ~Card_11(void)
{
}
