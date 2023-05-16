#pragma once

#include "Action.h"

class AddLadderAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition startPos; // 1- The start position of the ladder
	CellPosition endPos;   // 2- The end position of the ladder
	Ladder* Ladders[99];
	int LaddersNum = 0;
	// Note: These parameters should be read in ReadActionParameters()

public:

	AddLadderAction(ApplicationManager *pApp); // A Constructor

	bool CheckLadderOverLap(CellPosition start, CellPosition end);

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	bool isValid();

	virtual void Execute(); // Creates a new Ladder Object 
	                        // then Sets this Ladder object to the GameObject Pointer of its Cell
	

	virtual ~AddLadderAction(); // Virtual Destructor

};

