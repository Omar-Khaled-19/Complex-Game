#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"


InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please enter the dice value: ");

	DiceValue = pIn->GetInteger(pOut);

	while (DiceValue < 0 || DiceValue>6)
	{
		pOut->PrintMessage("Please enter a value from 0 to 6");
		DiceValue = pIn->GetInteger(pOut);
	}

	// or  do
	//{
		//DiceValue = pIn->GetInteger(pOut);
	//} while (DiceValue < 0 || DiceValue>6);


}

void InputDiceValueAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if (pGrid->GetEndGame())
	{
		pOut->PrintMessage("The game has ended. You can't enter a dice value. Click here.. ");
		return;
	}

	ReadActionParameters();

	Player* pPlayer = pGrid->GetCurrentPlayer();

	pPlayer->Move(pGrid, DiceValue);

	pGrid->AdvanceCurrentPlayer();




}

InputDiceValueAction::~InputDiceValueAction()
{
}