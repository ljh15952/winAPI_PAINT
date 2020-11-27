#pragma once
#include "Group.h"
class Paste :
	public Group
{
public:
	Paste(Vector2 v1, Vector2 v2) : Group(v1, v2) {}

	void pasteAll();
};

