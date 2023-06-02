#pragma once
#include "Include.h"

class Bitmap;
class Object;
class Stage
{
private:
	Object* object;
	map<string, Bitmap*>* m_mapImageList;
public:
	void Start();
	void Update();
	void Render(HDC _hdc);
	void Destroy();
public:
	Stage();
	~Stage();
};

