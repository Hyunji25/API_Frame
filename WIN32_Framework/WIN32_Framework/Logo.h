#pragma once
#include "Scene.h"

class Logo
{
public:
	void Start();
	int Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Logo();
	virtual ~Logo();
};

