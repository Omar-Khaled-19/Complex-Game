#include "Card_8.h"

Card_8::Card_8(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

void Card_8::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("The amount of coins needed to go out of the prison: ");

	amount = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	pGrid->GetOutput()->ClearStatusBar();
}

void Card_8::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	pGrid->PrintErrorMessage("Card 8 : You must pay " + to_string(amount) + " OR you won't move for 3 turns");
	pGrid->PrintErrorMessage("Please enter 1 if you will pay or 0 if not");
	
	bool b = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	
	if (b)
		pPlayer->SetWallet(pPlayer->GetWallet() - amount);
	else
	{
		pPlayer->SetPrison(4);
	}
}