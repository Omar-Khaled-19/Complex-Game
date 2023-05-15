#pragma once
#include "Action.h"
#include"Grid.h"
class DeleteGameObjectAction :public Action
{
	CellPosition pos;
public:
	DeleteGameObjectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

