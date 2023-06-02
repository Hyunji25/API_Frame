#include "Stage.h"
#include "Tile.h"
#include "ImageManager.h"
#include "Bitmap.h"
#include "Object.h"

Stage::Stage() : object(nullptr)
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	object = new Tile;
	object->Start();

	m_mapImageList = ImageManager::GetInstance()->GetImageList();

	(*m_mapImageList)["Tile"] = (new Bitmap)->LoadBmp(L"../Resource/Tile.bmp");

	Object::SetImageList(m_mapImageList);
}

void Stage::Update()
{
	object->Update();
}

void Stage::Render(HDC _hdc)
{
	BitBlt((*m_mapImageList)["Tile"]->GetMemDC(),
		0, 0, WIDTH, HEIGHT,
		(*m_mapImageList)["Tile"]->GetMemDC(),
		0, 0,
		SRCCOPY);


	object->Render(_hdc);
}

void Stage::Destroy()
{
	delete object;
	object = nullptr;
}

