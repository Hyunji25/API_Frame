#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "ObjectPool.h"
#include "Prototype.h"

#include <tchar.h>

Stage::Stage() : m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	GetSingle(Prototype)->Start();

	{
		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject("Player");

		if (ProtoObj != nullptr)
		{
			m_pPlayer = ProtoObj->Clone();
			m_pPlayer->Start();
		}
	}

	{
		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject("Enemy");

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			ObjectManager::GetInstance()->AddObject(
				Object->Start());
		}
	}

	EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	ObjectManager::GetInstance()->Update();

	/*
	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Update();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Update();
	}
	else
		BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	*/

	return 0;
}

void Stage::Render(HDC hdc)
{
	if (m_pPlayer)
		m_pPlayer->Render(hdc);

	ObjectManager::GetInstance()->Render(hdc);

	list<GameObject*>* enemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<GameObject*>* normalList = ObjectManager::GetInstance()->GetObjectList("NormalBullet");
	list<GameObject*>* guideList = ObjectManager::GetInstance()->GetObjectList("GuideBullet");

#define DEBUG 1

#ifdef DEBUG

#endif // DEBUG
	
	if (enemyList != nullptr && !enemyList->empty())
	{
		// ** Buffer ����
		// ** �迭�� ���̴� �߿����� ���� (����ϸ� ��)
		char* enemyBuffer = new char[128];

		// ** ������ ���ڿ��� ��ȯ	10������ ��ȯ��
		_itoa((int)enemyList->size(), enemyBuffer, 10);

		// ** ���ڿ� �����͸� string���� ��ȯ
		string str(enemyBuffer);

		// ** ���ڿ� ������ ����
		delete[] enemyBuffer;
		enemyBuffer = nullptr;

		// ** �����ڵ� ���·� ����
		wchar_t* t = new wchar_t[str.size()];

		// ** ���ڿ� ����
		mbstowcs(t, str.c_str(), str.size());

		// ** ���
		TextOut(hdc, 50, 50, (LPCWSTR)t, str.size());
	}

	if (normalList != nullptr && !normalList->empty())
	{
		char* NormalBuffer = new char[128];	
		_itoa((int)enemyList->size(), NormalBuffer, 10);

		string str(NormalBuffer);

		delete[] NormalBuffer;
		NormalBuffer = nullptr;

		wchar_t* t = new wchar_t[str.size()];
		mbstowcs(t, str.c_str(), str.size());

		TextOut(hdc, 50, 50, (LPCWSTR)t, str.size());
	}

	if (guideList != nullptr && !guideList->empty())
	{
		char* GuideBuffer = new char[128];
		_itoa((int)enemyList->size(), GuideBuffer, 10);

		string str(GuideBuffer);

		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		wchar_t* t = new wchar_t[str.size()];
		mbstowcs(t, str.c_str(), str.size());

		TextOut(hdc, 50, 50, (LPCWSTR)t, str.size());
	}

	list<GameObject*>* normalList = GetSingle(ObjectPool)->GetList("NormalBullet");
	list<GameObject*>* normalList = GetSingle(ObjectPool)->GetList("NormalBullet");

	if (normalList != nullptr && !normalList->empty())
	{
		char* NormalBuffer = new char[128];
		_itoa((int)enemyList->size(), NormalBuffer, 10);

		string str(NormalBuffer);

		delete[] NormalBuffer;
		NormalBuffer = nullptr;

		wchar_t* t = new wchar_t[str.size()];
		mbstowcs(t, str.c_str(), str.size());

		TextOut(hdc, 120, 50, (LPCWSTR)t, str.size());


	if (guideList != nullptr && !guideList->empty())
	{
		char* GuideBuffer = new char[128];
		_itoa((int)enemyList->size(), GuideBuffer, 10);

		string str(GuideBuffer);

		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		wchar_t* t = new wchar_t[str.size()];
		mbstowcs(t, str.c_str(), str.size());

		TextOut(hdc, 120, 50, (LPCWSTR)t, str.size());
	}

	/*
	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Render(hdc);
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Render(hdc);
	}
	*/
}

void Stage::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		EnemyList->clear();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		BulletList->clear();
	}
}