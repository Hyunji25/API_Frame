#pragma once
#include "Include.h"

class MainUpdate
{
private :
	HDC m_hdc;
	RECT rcPoint;
	int StartX, StartY;
	int EndX, EndY;
public:
	void Start();
	void Update();
	void Render();
	void Destroy();
public:
	MainUpdate();
	~MainUpdate();
};

