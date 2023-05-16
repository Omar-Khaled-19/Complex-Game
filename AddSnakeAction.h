#pragma once
#include "Action.h"
class AddSnakeAction : public Action
{
	CellPosition startPos; 
	CellPosition endPos;
	Snake* Snakes[99];
	int SnakesNum = 0;
public:
	
	AddSnakeAction(ApplicationManager* pApp);       //the constructor

	bool CheckSnakeOverLap(CellPosition start, CellPosition end);

	virtual void ReadActionParameters(); // Reads the action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new snake Object then Sets this  object to the GameObject Pointer of its Cell

	bool isValid();
	bool overlaps( Snake& other)  ;

	virtual ~AddSnakeAction();       

};

