#pragma once
#include "Action.h"
#include"Grid.h"
class SwitchToPlayModeAction :public Action
{public:
    SwitchToPlayModeAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();
};

