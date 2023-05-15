#pragma once
#include "Action.h"
#include"Grid.h"
#include"Ladder.h"
#include"Snake.h"
#include"GameObject.h"
#include"Card.h"
class OpenGridAction :public Action
{
public :
	OpenGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

