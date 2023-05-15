#include "Snake.h"

int Snake::snakesnum = 0;
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

    this->endCellPos = endCellPos;

    snakesnum++;
}

void Snake::Draw(Output* pOut) const
{
    pOut->DrawSnake(position, endCellPos);

}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
    pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");

    pGrid->UpdatePlayerCell(pPlayer, endCellPos);

    if (pPlayer->GetCell()->HasGameObject())
    {
        GameObject* pGobject = pPlayer->GetCell()->GetGameObject();
        pGobject->Apply(pGrid, pPlayer);
    }

}

CellPosition Snake::GetEndPosition() const
{
    return endCellPos;
}

void Snake::Save(ofstream& OutFile, int type)
{
    if (OutFile.is_open())
    {

        OutFile << position.GetCellNum() << "      " << endCellPos.GetCellNum() << endl;


    }
}

void Snake::Load(ifstream& Infile)
{
    int x, y;
    Infile >> x >> y;
    CellPosition X(x), Y(y);
    position = X;

    endCellPos = Y;
}

int Snake::GetSnakesNum()
{
    return snakesnum;
}

Snake::~Snake()
{
    snakesnum--;
}
