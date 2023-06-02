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
		// �� �� ���� �Ÿ� < ������
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
	TransparentBlt(_hdc,	  // ������ ���� �׸���
		int(position.x - scale.x * 0.5f),	// ������ ���� ������ X
		int(position.y - scale.y * 0.5f), 	// ������ ���� ������ Y
		(int)scale.x,		// ������ ���� ���κ� X
		(int)scale.y,		// ������ ���� ���κ� Y
		(*m_ImageList)[Key]->GetMemDC(),	// ������ �̹��� (������)
		scale.x * frame.CountX, // ������ ������ X
		scale.y * frame.CountY,	// ������ ������ Y
		(int)scale.x, 			// ����� �̹����� ũ�� ��ŭ X
		(int)scale.y,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));		// �ش� ������ ����
	
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

