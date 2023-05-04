#pragma once
#include "Scene.h"

class Menu
{
public:
	void Start();
	int Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Menu();
	virtual ~Menu();
};

