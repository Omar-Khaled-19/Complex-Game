#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
    if (endCellPos.VCell() <= startCellPos.VCell() || endCellPos.HCell() != startCellPos.HCell()) // added by amr

        this->endCellPos = endCellPos;
}

void Snake::Draw(Output* pOut) const
{
    pOut->DrawSnake(position, endCellPos);

}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("You have reached a snake. Click to continue ...");

	pIn->GetUserAction();

	pGrid->UpdatePlayerCell(pPlayer , endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
    return CellPosition();
}

Snake::~Snake()
{
}
