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

	pGrid->PrintErrorMessage("Creating New Game.. ");

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