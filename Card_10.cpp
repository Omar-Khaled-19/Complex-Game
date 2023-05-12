#include"Card_10.h"

Card_10::Card_10(const CellPosition& pos) : Card(pos)
{
	cardNumber = 10;
}

void Card_10::ReadCardParameters(Grid* pGrid)
{
}

void Card_10::Apply(Grid* pGrid, Player* pPlayer)
{
}

Card_10 :: ~Card_10(void)
{}