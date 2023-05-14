#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp): Action(pApp)
{
	pManager = pApp;
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Cut Card: Click on the card you want to cut . . . ");
	CardPosition = pIn->GetCellClicked();

}

void CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	Card* pCard;
	if (CardPosition.IsValidCell())
	{
		card1 = pGrid->PosHasCard(CardPosition);
		int x = card1->GetCardNumber();
		if (!card1)
		{
			pGrid->PrintErrorMessage("the cell you clicked doesn't have a card : click to continue");
			return;
		}
		else {
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
				// A- Add the remaining cases
			}
			pCard->transfereCardParameters(card1);
			pGrid->SetClipboard(pCard);
			pGrid->PrintErrorMessage("cut : click to continue");
			pGrid->RemoveObjectFromCell(CardPosition);
		}
	}
	else
	{
		pGrid->PrintErrorMessage("the cell you clicked on is not an appropriate cell : click to continue");
	}
}
