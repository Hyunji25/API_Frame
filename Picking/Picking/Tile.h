#pragma once
#include "Object.h"

class Tile : public Object
{
private:
	int check;
	string Key;
	Vector3 position;
	Vector3 scale;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Destroy()override;
public:
	Tile();
	~Tile();
};

