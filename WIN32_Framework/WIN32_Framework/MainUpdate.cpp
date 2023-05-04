#include "MainUpdate.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "SceneManager.h"

MainUpdate::MainUpdate() : m_pPlayer(NULL), m_pEnemy(NULL)
{

}

MainUpdate::~MainUpdate()
{
	Destroy();
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{

}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, WIDTH, HEIGHT);

	
}

void MainUpdate::Destroy()
{
	if (m_pPlayer) 
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}
}

