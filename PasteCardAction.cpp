#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Paste Card: Click on the card you want to Paste to . . . ");
	CardPosition = pIn->GetCellClicked();




}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	
	Output* pOut = pGrid->GetOutput();
    
	Input* pIn = pGrid->GetInput();
	
	if (CardPosition.IsValidCell())
	{
		int x  = (pGrid->GetClipboard())->GetCardNumber();

		Card* card1 = pGrid->GetClipboard();

		Card* pCard;

		if (card1 != NULL)
		{
			switch (x)
			{
			case 1:
				pCard = new CardOne(CardPosition);
				break;
			case 2:
				pCard = new Card_2(CardPosition);
				break;
			case 3:
				pCard = new Card_3(CardPosition);
				break;
			case 4:
				pCard = new Card_4(CardPosition);
				break;
			case 5:
				pCard = new Card_5(CardPosition);
				break;
			case 6:
				pCard = new Card_6(CardPosition);
				break;
			case 7:
				pCard = new Card_7(CardPosition);
				break;
			case 8:
				pCard = new Card_8(CardPosition);
				break;
			case 9:
				pCard = new Card_9(CardPosition);
				break;
			case 10:
				pCard = new Card_10(CardPosition);
				break;
			case 11:
				pCard = new Card_11(CardPosition);
				break;
			case 12:
				pCard = new Card_12(CardPosition);
				break;
			}

			pCard->transfereCardParameters(card1);

			pGrid->AddObjectToCell(pCard);

			pGrid->PrintErrorMessage("pasted  : click to continue . . . ");
		}
		else
		{
			pGrid->PrintErrorMessage("there is no card in the clipboard : click to continue");
		}
	}
	else
	{
		pGrid->PrintErrorMessage("the cell you clicked on is not an appropriate cell : click to continue");
	}
}
