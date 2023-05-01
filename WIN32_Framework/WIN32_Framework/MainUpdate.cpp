#include "MainUpdate.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	 
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	rcPoint.left = 100;
	rcPoint.top = 100;
	rcPoint.right = 200;
	rcPoint.bottom = 200;

	StartX = 100;	// left
	StartY = 100;	// top

	EndX = 200;	// right
	EndY = 200;	// bottom
}

void MainUpdate::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		StartY -= 100;
		EndY = StartY + 100;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		StartY += 100;
		EndY = StartY + 100;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		rcPoint.left += -1;
		rcPoint.right += -1;

		StartX -= 100;
		EndX = StartX + 100;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		rcPoint.left += 1;
		rcPoint.right += 1;

		/*StartX += 100;
		EndX = StartX + 100;*/
	}
}

void MainUpdate::Render()
{
	//Rectangle(m_hdc, 0, 0, 1280, 720);
	Rectangle(m_hdc, rcPoint.left, rcPoint.top, rcPoint.right, rcPoint.bottom);
	//Rectangle(m_hdc, StartX, StartY, EndX, EndY);
}

void MainUpdate::Destroy()
{

}


// Ω∫∆‰¿ÃΩ∫πŸ ¥≠∑∂¿ª ∂ß √—æÀ ΩÓ±‚