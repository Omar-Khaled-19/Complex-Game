#pragma once
#include "GameObject.h"
#include "Player.h"

class Snake : public GameObject
{

	CellPosition endCellPos;
	

	static int snakesnum;

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos);

	virtual void Draw(Output* pOut) const;

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	CellPosition GetEndPosition() const;


	virtual void Save(ofstream& OutFile, int type);

	virtual void Load(ifstream& Infile);

	static int GetSnakesNum();

	virtual ~Snake();

};

