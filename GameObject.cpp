#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

int GameObject::GetObjCellNum() const
{
	return position.GetCellNum();
}

GameObject::~GameObject()
{
}