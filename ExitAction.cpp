#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
}

void ExitAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->DeleteAll();
}

ExitAction::~ExitAction()
{
}