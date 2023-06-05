#include "Stage.h"
#include "Tile.h"
#include "Bitmap.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	ImageList["Tile"] = (new Bitmap)->LoadBmp(L"../Resource/Tile.bmp");

	int mine = 150;

	for (int y = 0; y < COUNT_Y; ++y)
	{
		for (int x = 0; x < COUNT_X; ++x)
		{
			Object* tile = new Tile;
			tile->Start();
			
			int random = rand() % 100;

			if (mine)
			{
				--mine;
				tile->SetOption(8);
			}
			
			tile->SetPosition(
				Vector3(
					(x * SCALE_X) + (SCALE_X * 0.5f),
					(y * SCALE_Y) + (SCALE_Y * 0.5f)));

			TileList.push_back(tile);
		}
	}

	ULONGLONG Time = GetTickCount64();
	
	while (true)
	{
		if (Time + 100 > GetTickCount64())
		{
			int temp, dest;

			temp = rand() % TileList.size();
			dest = rand() % TileList.size();

			if (temp == dest)
				continue;

			int pTile = TileList[temp]->GetOption();
			TileList[temp]->SetOption(TileList[dest]->GetOption());
			TileList[dest]->SetOption(pTile);
		}
		else
			break;
	}

	// ** 모든 타일을 확인
	// ** 주변 타일 중에 지뢰가 몇개 있는지 확인 후 타일을 설정
	
	int index = COUNT_X;
	int boom = 0;

	for (int i = 0; i < TileList.size(); ++i)
	{
		if (index < MAX &&
			TileList[index - COUNT_X]->GetOption() == 10)
			++boom;

		if (index < (MAX - COUNT_X) &&
			TileList[index + COUNT_X]->GetOption() == 10)
			++boom;

		if (index % 5 != 0 &&
			TileList[index - 1]->GetOption() == 10)
			++boom;

		if (index % 5 - COUNT_X - 1 != 0 &&
			TileList[index + 1]->GetOption() == 10)
			++boom;

		if (index < MAX && index % 5 != 0 &&
			TileList[index - COUNT_X - 1]->GetOption() == 10)
			++boom;
		
		if (index < MAX && index % 5 - COUNT_X - 1 != 0 &&
			TileList[index - COUNT_X + 1]->GetOption() == 10)
			++boom;

		if (index < (MAX - COUNT_X) && index % 5 != 0 &&
			TileList[index + COUNT_X - 1]->GetOption() == 10)
			++boom;

		if (index < (MAX - COUNT_X) && index % 5 - COUNT_X - 1 != 0 &&
			TileList[index + COUNT_X + 1]->GetOption() == 10)
			++boom;

		TileList[i]->SetOption(boom + 2);
	}

	Object::SetImageList(&ImageList);
}

void Stage::Update()
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		int result = (*iter)->Update();

		if (result == 1)
		{
			// 지뢰
		}
	}
}

void Stage::Render(HDC _hdc)
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		(*iter)->Render(_hdc);
	}

}

void Stage::Destroy()
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	TileList.clear();
}