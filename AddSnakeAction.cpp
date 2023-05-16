#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"


AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters
	if (startPos.GetCellNum() < 11  )
	
		pGrid->PrintErrorMessage("Error: Snake can't be put in the first row ! Click to continue ...");
	
	








	// Clear messages
	pOut->ClearStatusBar();
}

bool AddSnakeAction::isValid()
{
	Grid* pGrid = pManager->GetGrid();

	if (endPos.VCell() <= startPos.VCell() || endPos.HCell() != startPos.HCell() || pGrid->PosHasLadderorSnake(endPos) || startPos.GetCellNum()==99 || endPos.GetCellNum()==1)
		return false;
	
	return true;
}

//bool AddSnakeAction::CheckSnakeOverLap(CellPosition start, CellPosition end)
//{
//	for (int i = 0; i < SnakesNum; i++)
//	{
//		if (end.VCell() < Snakes[i]->GetSnakeStartPositionInt() && start.VCell() > Snakes[i]->GetSnakeEndPositionInt() && end.VCell() == Snakes[i]->GetSnakeEndPositionInt() && start.VCell() == Snakes[i]->GetSnakeStartPositionInt())
//		{
//			return true;
//		}
//	}
//	return false;
//
//}

void AddSnakeAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();           
	CellPosition start;
	CellPosition end;
	Snake* pSnake = new Snake(startPos, endPos);
	if (!isValid()||pGrid->IsOcuppiedSnake(pSnake))
	{
		pGrid->PrintErrorMessage("InValid Snake! Click to back to game ...");
		delete pSnake;
		return;
	}
	

	
    /*Snakes[SnakesNum] = pSnake;
	SnakesNum++;*/

	bool added = pGrid->AddObjectToCell(pSnake);

	if (!added)
	{
		
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	
	pGrid->SetOccuSnakecells(pSnake);
}


