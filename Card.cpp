#include "Card.h"

int Card::cardnums = 0;
Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
	position = pos;

	cardnums++;
}

void Card::SetCardNumber(int cnum)
{
	if( cnum > 0 && cnum < 13)
		cardNumber = cnum;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Output function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, int type)
{
	if (OutFile.is_open())
	{

		OutFile << cardNumber << "      " << position.GetCellNum() <<  endl;


	}
}

void Card::transfereCardParameters(Card* pCard)
{
}

int Card::GetCardNums()
{
	return cardnums;
}

Card::~Card()
{
	cardnums--;
}
