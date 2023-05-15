#include "Card_6.h"

Card_6::Card_6(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}

void Card_6::ReadCardParameters(Grid* pGrid)
{
	pGrid->PrintErrorMessage("Cell to move to: ");
	
	cellNum = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	pGrid->GetOutput()->ClearStatusBar();

	while (cellNum == position.GetCellNum())
	{
		pGrid->PrintErrorMessage("Invalid cell please try again");
		cellNum = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	}
}

void Card_6::transfereCardParameters(Card* pCard)
{
	cellNum = ((Card_6*)pCard)->cellNum;
}

void Card_6::Save(ofstream& OutFile, int type)
{
	if (OutFile.is_open())
	{

		OutFile << cardNumber << "      " << position.GetCellNum() << "       " << cellNum << endl;


	}
}

void Card_6::Load(ifstream& Infile)
{
	int x, y;
	Infile >> x >> y ;

	position = x;
	cellNum = y;
}

void Card_6::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 6 : Move the player to the cell with cell number: " + to_string(cellNum) );

	pGrid->UpdatePlayerCell(pPlayer, cellNum);
	if (pGrid->PosHasGameObject(CellPosition(cellNum)))
		pGrid->PosHasGameObject(CellPosition(cellNum))->Apply(pGrid, pPlayer);
}

