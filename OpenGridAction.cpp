#include "OpenGridAction.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp):Action(pApp)
{
	pManager = pApp;
}

void OpenGridAction::ReadActionParameters()
{
}

void OpenGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ifstream Infile;
	Infile.open("save.txt");
	int x; 
	Infile >> x;
	for(int i = 0;  i< x; i++)
	{
		Ladder* ladder = new Ladder(0,0);
		ladder->Load(Infile);
		pGrid->AddObjectToCell(ladder);
	}
	int y;
	Infile >> y;
	for (int i = 0; i < y; i++)
	{
		Snake* snake = new Snake(0, 0);
		snake->Load(Infile);
		pGrid->AddObjectToCell(snake);
	}
	int z; 
	Infile >> z; 
	for (int i = 0; i < z; i++)
	{
		Card* card = new Card(0);
		card->Load(Infile);
		pGrid->AddObjectToCell(card);
	}
	Infile.close();
}
