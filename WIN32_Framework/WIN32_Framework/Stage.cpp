#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Start()
{
	m_pPlayer = new Player();
	m_pPlayer->Start();

	m_pEnemy = new Enemy();
	m_pEnemy->Start();

	ObjectManager::GetInstance()->AddObject(new Enemy)->Start());
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	return 0;
}

void Stage::Render(HDC hdc)
{
}

void Stage::Destroy()
{
}

list<GameObject*>* EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
list<GameObject*>* BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");

if (m_pPlayer)
m_pPlayer->Render(m_hdc);

if (EnemyList != nullptr && !EnemyList->empty())
{
	for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		(*iter)->Render(m_hdc);
}

if (BulletList != nullptr && !BulletList->empty())
{
	for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		(*iter)->Render(m_hdc);
}