#pragma once
#include "Include.h"

class Scene
{
public:
	void Start();
	int Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Scene();
	virtual ~Scene();
};

