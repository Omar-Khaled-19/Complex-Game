#include "NewGameAction.h"

#include "Input.h"
#include "Output.h"  //Added
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Do You want to start a new game? Enter 1 for Yes or any other key for No. ");

	if (pIn->GetSrting(pOut) != "1")
		return;

	for (int i = 0; i < 4; i++)
	 {
	 Player* pPlayer = pGrid->GetCurrentPlayer();
	 pPlayer->ResetPlayer(pGrid);

	pGrid->AdvanceCurrentPlayer();
	 }

	            pGrid->SetcurrPlayerNumber(0);

}

NewGameAction::~NewGameAction()
{
}