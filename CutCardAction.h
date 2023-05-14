#pragma once
#include "Action.h"
#include "Card.h"
#include"AddCardAction.h"
#include "Grid.h"
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
class CutCardAction :public Action
{
	CellPosition CardPosition;
	Card* card1;

public:
	CutCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

