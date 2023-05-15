#pragma once
#include "Action.h"
class AddSnakeAction : public Action
{
	CellPosition startPos; 
	CellPosition endPos;
public:
	
	AddSnakeAction(ApplicationManager* pApp);       //the constructor

	virtual void ReadActionParameters(); // Reads the action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new snake Object then Sets this  object to the GameObject Pointer of its Cell

	bool isValid();
	bool overlaps( Snake& other)  ;

	virtual ~AddSnakeAction();       

};

