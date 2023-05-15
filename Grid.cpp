#include "Grid.h"
#include"Snake.h"
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed
		delete CellList[pos.VCell()][pos.HCell()]->GetGameObject(); // added by shereef
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}

void Grid::SaveAll(ofstream& OutFile, int type)    // added by shereef
{
	GameObject* Arrgo[99];
	int laddersnum = 0;

	int snakesnum = 0;

	int cardsnum = 0;

	Ladder* Arrladder[99];

	Snake* ArrSnakes[99];

	Card* ArrCards[99];

	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder())
			{
				Arrladder[laddersnum] = CellList[i][j]->HasLadder();
				laddersnum++;
			}
			else if (CellList[i][j]->HasSnake())
			{
				ArrSnakes[snakesnum] = CellList[i][j]->HasSnake();
				snakesnum++;
			}
			else if (CellList[i][j]->HasCard())
			{
				ArrCards[cardsnum] = CellList[i][j]->HasCard();
				cardsnum++;
			}
		}
	}

	int objectsnum = laddersnum + snakesnum + cardsnum;

	for (int i = 0; i < laddersnum; i++)
	{
		Arrgo[i] = Arrladder[i];

	}

	for (int i = 0; i < snakesnum; i++)
	{

		Arrgo[i + laddersnum] = ArrSnakes[i];
	}
	for (int i = 0; i < cardsnum; i++)
	{
		Arrgo[i + laddersnum + snakesnum] = ArrCards[i];

	}

	OutFile << laddersnum << endl;
	
		for (int i = 0; i < laddersnum; i++)
	{
			Arrgo[i]->Save(OutFile, type);
	}

		OutFile << snakesnum << endl;

		for (int i = 0; i < snakesnum; i++)
		{

			Arrgo[i + laddersnum]->Save(OutFile, type);
		}
		OutFile << cardsnum << endl;
		for (int i = 0; i < cardsnum; i++)
		{
			Arrgo[i + laddersnum + snakesnum]->Save(OutFile, type);

		}
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

Card* Grid::PosHasCard(CellPosition& pos)                                   //added by shereef
{
	return CellList[pos.VCell()][pos.HCell()]->HasCard();
}

GameObject* Grid::PosHasGameObject(CellPosition& pos)                           //added by shereef
{
	return CellList[pos.VCell()][pos.HCell()]->GetGameObject();
}


bool Grid::PosHasLadderorSnake(CellPosition& pos)
{
	if (CellList[pos.VCell()][pos.HCell()]->HasLadder() || CellList[pos.VCell()][pos.HCell()]->HasSnake())
		return true;

	   return false;
}


// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			
			Ladder* pladder = CellList[i][j]->HasLadder();
			if (pladder != NULL)
				return pladder;

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Player* Grid::GetNearestPlayer(Player* p)
{
	int min = 100;
	int z = 5;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (p == PlayerList[i])
			continue;

		if (PlayerList[i]->GetStepCount() - p->GetStepCount() < 0)
			continue;

		if (PlayerList[i]->GetStepCount() - p->GetStepCount() < min)
		{
			min = PlayerList[i]->GetStepCount() - p->GetStepCount();
			z = i;
		}
	}
	if (z == 5)
		return NULL;
	return PlayerList[z];
}

Player* Grid::LeastWalletPlayer(Player* p)
{
	int z;
	int min = INFINITY;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (p == PlayerList[i])
			continue;

		if (PlayerList[i]->GetWallet() < min)
			z = i;
	}
	return PlayerList[z];
}

void Grid::SetcurrPlayerNumber(int playerNum)
{
	currPlayerNumber = playerNum;
}

// Bonus Functions

void Grid::SpAttacks()
{
	PrintErrorMessage("Choose which special attak to use 1:I , 2:F , 3:P, 4:L ");
	int c = pIn->GetInteger(pOut);
	if (c == 1)
	{
		PrintErrorMessage("Choose a player to ice him");
		int i = pIn->GetInteger(pOut);
		Ice(i);
		return;
	}
	else if (c == 2)
	{
		PrintErrorMessage("Choose a player to fire him");
		int i = pIn->GetInteger(pOut);
		PlayerList[i]->SetFire(4);
		return;
	}
	else if (c == 3)
	{
		PrintErrorMessage("Choose a player to poison him");
		int i = pIn->GetInteger(pOut);
		PlayerList[i]->SetPoison(6);
		return;
	}
	else
	{
		Lighting();
		return;
	}
}

void Grid::Ice(int i)
{
	PlayerList[i]->SetCard_4(true);
}

void Grid::Fire(Player *pPlayer)
{
	pPlayer->SetWallet(pPlayer->GetWallet() - 20);
}

void Grid::Poison(int i)
{
	PlayerList[i]->SetPoison(6);
}

void Grid::Lighting()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (PlayerList[i] == GetCurrentPlayer())
			continue;

		PlayerList[i]->SetWallet(PlayerList[i]->GetWallet() - 20);
	}
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}