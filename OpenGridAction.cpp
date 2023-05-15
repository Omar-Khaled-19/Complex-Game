#include "OpenGridAction.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp):Action(pApp)
{
	pManager = pApp;
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->PrintErrorMessage("type the filename you want to open and its extension ");
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	filename =pIn->GetSrting(pOut);

}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	ifstream Infile;
	Infile.open(filename);
	if (Infile.is_open()) 
	{


		int x;

		Infile >> x;
		for (int i = 0; i < x; i++)
		{
			Ladder* ladder = new Ladder(0, 0);
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
			Card* pCard;
			int CardNumber;
			Infile >> CardNumber;
			switch (CardNumber)
			{
			case 1:
				pCard = new CardOne(0);
				break;
			case 2:
				pCard = new Card_2(0);
				break;
			case 3:
				pCard = new Card_3(0);
				break;
			case 4:
				pCard = new Card_4(0);
				break;
			case 5:
				pCard = new Card_5(0);
				break;
			case 6:
				pCard = new Card_6(0);
				break;
			case 7:
				pCard = new Card_7(0);
				break;
			case 8:
				pCard = new Card_8(0);
				break;
			case 9:
				pCard = new Card_9(0);
				break;
			case 10:
				pCard = new Card_10(0);
				break;
			case 11:
				pCard = new Card_11(0);
				break;
			case 12:
				pCard = new Card_12(0);
				break;
			}
			pCard->Load(Infile);
			pGrid->AddObjectToCell(pCard);
		}
		Infile.close();
		pGrid->PrintErrorMessage("opened " + filename + "  click to continue");
	}
	else
	{
		pGrid->PrintErrorMessage("the file name you typed is incorrect :  click to continue   .   .   .");
	}
}
