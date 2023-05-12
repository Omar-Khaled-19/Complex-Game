#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

    this->endCellPos = endCellPos;
}

void Snake::Draw(Output* pOut) const
{
    pOut->DrawSnake(position, endCellPos);

}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
    pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");

    pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
    return endCellPos;
}

Snake::~Snake()
{
