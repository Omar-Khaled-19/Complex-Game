#include "SaveGridAction.h"
#include "Card_9.h"
#include "Card_10.h"
#include "Card_11.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->PrintErrorMessage("type the filename you want to save to  ");
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	filename = pIn->GetSrting(pOut);
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
Grid* pGrid = pManager->GetGrid();
ofstream Outfile;
Outfile.open(filename+".txt");
pGrid->SaveAll(Outfile,1);
Card_9::saved = false;
Card_10::saved = false;
Card_11::saved = false;
Outfile.close();
pGrid->PrintErrorMessage("saved " + filename + "  click to continue");
}
