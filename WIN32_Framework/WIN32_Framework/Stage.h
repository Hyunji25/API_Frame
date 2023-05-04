#pragma once
#include "Scene.h"

class GameObject;
class Stage
{
private: 

public:
	void Start();
	int Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Stage();
	virtual ~Stage();
};

