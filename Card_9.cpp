#include "Card_9.h"


Card_9::Card_9(const CellPosition& pos) : Card(pos)
{
	cardNumber = 9;
}

void Card_9::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("The amount of coins needed to buy all cells containing this card no. : ");
	price = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	pGrid->GetOutput()->ClearStatusBar();
}

void Card_9::transfereCardParameters(Card* pCard)
{
}

void Card_9::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Please enter 1 if you'll buy all cells containing this card no. or 0 if you'll not");
	bool buy= pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	if (buy)
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - price);
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j <9 ; j++) {
				
			
			}


		}


	}






}

Card_9::~Card_9(void)
{
}