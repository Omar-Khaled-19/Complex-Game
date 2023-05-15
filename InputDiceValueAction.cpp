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

	  do
	  {
	   pOut->PrintMessage("please enter a dice value between 1-6");

	   DiceValue = pIn->GetInteger(pOut);
	  }   while (DiceValue < 0 || DiceValue>6);

	  pOut->ClearStatusBar();
}

void InputDiceValueAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	
	if (pGrid->GetEndGame())
	{
		pGrid->PrintErrorMessage("The game has ended. You can't enter a dice value now.");
		return;
	}

	ReadActionParameters();

	Player* pPlayer = pGrid->GetCurrentPlayer();

	if (pPlayer->GetPrison())
	{
		pGrid->PrintErrorMessage("Sorry you can't play ");
		pGrid->AdvanceCurrentPlayer();
		return;
	}

	if (pPlayer->GetCard_4())
	{
		pGrid->PrintErrorMessage("Sorry you can't play ");
		pPlayer->SetCard_4(false);
		pGrid->AdvanceCurrentPlayer();
		return;
	}

	if (pPlayer->GetPoison())
	{
		DiceValue--;
	}

	if (pPlayer->GetFire())
	{
		pGrid->Fire(pPlayer);
	}

	pPlayer->Move(pGrid, DiceValue);

	if (pPlayer->GetCard_3())
	{
		pPlayer->SetCard_3(false);
		Execute();
	}

	pGrid->AdvanceCurrentPlayer();
}

InputDiceValueAction::~InputDiceValueAction()
{
}