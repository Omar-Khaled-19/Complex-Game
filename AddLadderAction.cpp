#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}


void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters

	

	// Clear messages
	pOut->ClearStatusBar();
}

bool AddLadderAction::isValid()
{
	Grid* pGrid = pManager->GetGrid();

	if(endPos.VCell()>=startPos.VCell() || endPos.HCell() != startPos.HCell() || pGrid->PosHasLadderorSnake(endPos))
	return false;
	
	return true;
}

//bool AddLadderAction::CheckLadderOverLap(CellPosition start , CellPosition end)
//{
//	for (int i = 0; i < LaddersNum; i++)
//	{
//		if (start.HCell() == Ladders[i]->GetPosition().HCell())
//		{
//			if (start.VCell() < Ladders[i]->GetEndPosition().VCell() && end.VCell() > Ladders[i]->GetPosition().VCell() && start.VCell() == Ladders[i]->GetPosition().VCell() && end.VCell() == Ladders[i]->GetEndPosition().VCell())
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//
//}

// Execute the action
void AddLadderAction::Execute()
{

	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();           // We get a pointer to the Grid from the ApplicationManager
	
	
	

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);
	

	if (!isValid())
	{
		pGrid->PrintErrorMessage("InValid Ladder! Click to back to game ...");
		return;
	}

	/*Ladders [LaddersNum] = pLadder;
	LaddersNum++;*/

	
	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
