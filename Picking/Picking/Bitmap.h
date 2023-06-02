#pragma once
#include "Include.h"
#include "MainUpdate.h"

class Bitmap : public MainUpdate
{
private:
	HDC m_MemDC;
	HBITMAP m_bitmap, m_Oldbitmap;
public:
	Bitmap* LoadBmp(LPCWSTR _FileName);
	void Release();
public:
	HDC GetMemDC() { return m_MemDC; }
public:
	Bitmap();
	~Bitmap();
};

