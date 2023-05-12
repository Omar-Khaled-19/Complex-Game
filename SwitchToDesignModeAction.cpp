#include "SwitchToDesignModeAction.h"

#include"Grid.h"
#include"Output.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDesignModeAction::ReadActionParameters()
{
}

void SwitchToDesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	pGrid->PrintErrorMessage("Switch To Design Mode. Click to continue.. ");

	pOut->CreateDesignModeToolBar();
}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{
}