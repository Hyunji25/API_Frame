#include "Tile.h"
#include "Bitmap.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::Start()
{
	check = 0;

	position = Vector3(100.0f, 100.0f);
	scale = Vector3(100.0f, 100.0f);

	Key = "Tile";
}

void Tile::Update()
{
	POINT ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	if (check)
	{
		if (position.x - (scale.x * 0.5f) < ptMouse.x &&
			position.y - (scale.y * 0.5f) < ptMouse.y &&
			ptMouse.x < position.x + (scale.x * 0.5f) &&
			ptMouse.y < position.y + (scale.y * 0.5f))
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				check = !check;
			}
		}
	}
	else
	{
		// 두 원 사이 거리 < 반지름
		float dx, dy;

		dx = ptMouse.x - position.x;
		dy = ptMouse.y - position.y;

		float distance = sqrt((dx * dx) + (dy * dy));

		if (distance < position.x - (scale.x * 0.5f))
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				check = !check;
			}
		}
	}
	
	if (GetAsyncKeyState(VK_RETURN))
	{
		check = !check;
		Sleep(80);
	}
}

void Tile::Render(HDC _hdc)
{
	TransparentBlt(_hdc,	  // 복사해 넣을 그림판
		int(position.x - scale.x * 0.5f),	// 복사할 영역 시작점 X
		int(position.y - scale.y * 0.5f), 	// 복사할 영역 시작점 Y
		(int)scale.x,		// 복사할 영역 끝부분 X
		(int)scale.y,		// 복사할 영역 끝부분 Y
		(*m_ImageList)[Key]->GetMemDC(),	// 복사할 이미지 (복사대상)
		scale.x * frame.CountX, // 복사할 시작점 X
		scale.y * frame.CountY,	// 복사할 시작점 Y
		(int)scale.x, 			// 출력할 이미지의 크기 만큼 X
		(int)scale.y,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));		// 해당 색상을 제외
	
	/*
	if (check)
		Rectangle(_hdc,
			int(position.x - (scale.x * 0.5f)),
			int(position.y - (scale.y * 0.5f)),
			int(position.x + (scale.x * 0.5f)),
			int(position.y + (scale.y * 0.5f)));
	else					
		Ellipse(_hdc,		
			int(position.x - (scale.x * 0.5f)),
			int(position.y - (scale.y * 0.5f)),
			int(position.x + (scale.x * 0.5f)),
			int(position.y + (scale.y * 0.5f)));
	*/
}

void Tile::Destroy()
{
}

