#include"Card_10.h"

Card_10::Card_10(const CellPosition& pos) : Card(pos)
{
	cardNumber = 10;
}

void Card_10::ReadCardParameters(Grid* pGrid)
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

void Card_10::transfereCardParameters(Card* pCard)
{
}

void Card_10::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pGrid->PrintErrorMessage("Please enter 1 if you'll buy all cells containing this card no. or 0 if you'll not");
	bool buy = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	if (buy)
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - price);



	}
}

Card_10 :: ~Card_10(void)
{}