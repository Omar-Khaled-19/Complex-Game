#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Paste Card: Click on the card you want to Paste to . . . ");
	CardPosition = pIn->GetCellClicked();




}

void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	
	Output* pOut = pGrid->GetOutput();
    
	Input* pIn = pGrid->GetInput();
	
	if (CardPosition.IsValidCell())
	{
		
















	}
	else
	{
		pGrid->PrintErrorMessage("the cell you clicked on is not an appropriate cell : click to continue");
	}
}
