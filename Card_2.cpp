#include "Card_2.h"

Card_2::Card_2(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

void Card_2::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 2 : Move to next ladder if exist. ");

	Ladder* pLadder = pGrid->GetNextLadder(position);

	if (pLadder == NULL)
		return;

	CellPosition LadderStartPos = pLadder->GetPosition();
	pGrid->UpdatePlayerCell(pPlayer, LadderStartPos);
	pLadder->Apply(pGrid, pPlayer);



}

Card_2::~Card_2()
{
}
