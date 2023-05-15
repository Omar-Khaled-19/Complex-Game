#include "Ladder.h"

#include "PLayer.h"

int Ladder::laddernums = 0;

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	this->endCellPos = endCellPos;
	laddernums++;
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	 /// Test

	if (pPlayer->GetCell()->HasGameObject())
	{
		GameObject* pGobject = pPlayer->GetCell()->GetGameObject();
		pGobject->Apply(pGrid, pPlayer);
	}
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& OutFile, int type)
{
	if (OutFile.is_open())
	{

		OutFile << position.GetCellNum() <<"      " << endCellPos.GetCellNum() << endl;


	}
}

void Ladder::Load(ifstream& Infile)
{
	int x, y;
	Infile >> x >> y;
	CellPosition X(x), Y(y);
	position = X;

	endCellPos = Y;
}

int Ladder::GetLadderNums()
{
	return laddernums;
}

Ladder::~Ladder()
{
	laddernums--;
}
