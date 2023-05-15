#pragma once
#include "GameObject.h"
class Snake : public GameObject
{

	CellPosition endCellPos;

	static int snakesnum;

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos);
	Snake();

	virtual void Draw(Output* pOut) const;

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	CellPosition GetEndPosition() const;

	virtual void Save(ofstream& OutFile, int type);

	static int GetSnakesNum();

	virtual ~Snake();

};

