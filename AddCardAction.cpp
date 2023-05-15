#include "AddCardAction.h"
#include"Grid.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "Card_2.h"
#include "Card_3.h"
#include "Card_4.h"
#include "Card_5.h"
#include "Card_6.h"
#include "Card_7.h"
#include "Card_8.h"
#include "Card_9.h"
#include "Card_10.h"
#include "Card_11.h"
#include "Card_12.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	pManager = pApp;
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("New Card: Enter its Number ...");
	
	cardNumber = pIn->GetInteger(pOut);


	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("New Card: Click on its Cell ...");
	cardPosition = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
	if (cardNumber > 12 || cardNumber < 1)
	{
		pGrid->PrintErrorMessage("Invalid card number , please re-enter");
		return;
	}


	
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	
	ReadActionParameters();
	
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new Card_2(cardPosition);
		break;
	case 3:
		pCard = new Card_3(cardPosition);
		break;
	case 4:
		pCard = new Card_4(cardPosition);
		break;
	case 5:
		pCard = new Card_5(cardPosition);
		break;
	case 6:
		pCard = new Card_6(cardPosition);
		break;
	case 7:
		pCard = new Card_7(cardPosition);
		break;
	case 8:
		pCard = new Card_8(cardPosition);
		break;
	case 9:
		pCard = new Card_9(cardPosition);
		break;
	case 10:
		pCard = new Card_10(cardPosition);
		break;
	case 11:
		pCard = new Card_11(cardPosition);
		break;
	case 12:
		pCard = new Card_12(cardPosition);
		break;
		// A- Add the remaining cases
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid(); 

		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		while (true)
		{
			if (pCard->GetCardNumber() == 9 && Card_9::added)
			{
				break;	
			}
			pCard->ReadCardParameters(pGrid); 
			break;
		}
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);


		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Card can't be added ! Click to continue ...");
		}
		
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
