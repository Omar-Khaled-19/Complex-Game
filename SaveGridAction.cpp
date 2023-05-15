#include "SaveGridAction.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->PrintErrorMessage("type the filename you want to save to and its extension ");
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	filename = pIn->GetSrting(pOut);
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
Grid* pGrid = pManager->GetGrid();
ofstream Outfile;
Outfile.open(filename);
pGrid->SaveAll(Outfile,1);
Outfile.close();
pGrid->PrintErrorMessage("saved " + filename + "  click to continue");
}
