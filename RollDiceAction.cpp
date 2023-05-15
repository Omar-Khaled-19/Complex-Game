#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	if (pGrid->GetEndGame())                                                           // by Amr
	{
		pGrid->PrintErrorMessage("The game has ended. You can't roll the dice. Click here.. ");
		return;
	}


	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

	// 3- Get the "current" player from pGrid

	Player* pPlayer = pGrid->GetCurrentPlayer();

	// 4- Move the currentPlayer using function Move of class player

	if (pPlayer->GetPrison())
	{
		pGrid->PrintErrorMessage("Sorry you can't play ");
		pGrid->AdvanceCurrentPlayer();
		return;
	}

	if (pPlayer->GetCard_4())
	{
		pGrid->PrintErrorMessage("Sorry you can't play ");
		pPlayer->SetCard_4(false);
		pGrid->AdvanceCurrentPlayer();
		return;
	}
	
	if (pPlayer->GetPoison())
	{
		pGrid->PrintErrorMessage("You got: " + to_string(diceNumber));
		diceNumber--;
	}

	if (pPlayer->GetFire())
	{
		pGrid->Fire(pPlayer);
	}

	pPlayer->Move(pGrid, diceNumber);

	if (pPlayer->GetCard_3())
	{
		pPlayer->SetCard_3(false);
		Execute();
	}

	// 5- Advance the current player number of pGrid

	pGrid->AdvanceCurrentPlayer();


	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}