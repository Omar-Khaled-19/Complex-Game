#pragma once
#include "Action.h"
#include"Grid.h"
class ExitAction :
	public Action
{
public:

	ExitAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~ExitAction();

};
