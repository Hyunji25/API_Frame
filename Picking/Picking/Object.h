#pragma once
#include "Include.h"

class Bitmap;
class Object
{
protected:
	Frame frame;
	ULONGLONG Time;

	static map<string, Bitmap*>* m_ImageList;
public:
	static void SetImageList(map<string, Bitmap*>* _ImageList) { m_ImageList = _ImageList; }
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Destroy()PURE;
public:
	Object();
	~Object();
};

