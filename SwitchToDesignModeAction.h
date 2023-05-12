#pragma once
#include "Action.h"
#include "Output.h"
class SwitchToDesignModeAction : public Action
{

    Output* pOut;

public:

    SwitchToDesignModeAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    ~SwitchToDesignModeAction();


};

