#include "SaveGridAction.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void SaveGridAction::ReadActionParameters()
{
}

void SaveGridAction::Execute()
{
Grid* pGrid = pManager->GetGrid();
ofstream Outfile;
Outfile.open("save.txt");
pGrid->SaveAll(Outfile,1);
Outfile.close();
pGrid->PrintErrorMessage("saved: click to continue . . .");
}
