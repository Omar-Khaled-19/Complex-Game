#include "DeleteGameObjectAction.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Copy Card: Click on the card you want to delete . . . ");
	pos = pIn->GetCellClicked();




}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pos.IsValidCell())
	{
		if ((pGrid->PosHasGameObject(pos))!=NULL)
		{
			pGrid->RemoveObjectFromCell(pos);
			pGrid->PrintErrorMessage("deleted : click to continue");
		}
		else
		{
			pGrid->PrintErrorMessage("the cell you clicked doesn't have an object : click to continue");
		}
	}
	else
	{
		pGrid->PrintErrorMessage("the cell you clicked on is not an appropriate cell : click to continue");
	}

}
