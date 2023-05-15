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

	if (endPos.VCell() <= startPos.VCell() || endPos.HCell() != startPos.HCell() || pGrid->PosHasLadderorSnake(endPos))
		return false;
	
	return true;
}

bool AddSnakeAction::overlaps( Snake& other)  
{
	CellPosition* start = & startPos;
	CellPosition* end = &endPos;
	CellPosition* endother = &other.GetPosition();
	CellPosition* startother = &other.GetPosition();

	return
		start == startother || start == endother ||
		end == startother || end == endother;

}

void AddSnakeAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();           

	if (!isValid())
	{
		pGrid->PrintErrorMessage("InValid Snake! Click to back to game ...");
		return;
	}
	

	Snake* pSnake = new Snake(startPos, endPos);

	bool added = pGrid->AddObjectToCell(pSnake);

	if (!added)
	{
		
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	

}


