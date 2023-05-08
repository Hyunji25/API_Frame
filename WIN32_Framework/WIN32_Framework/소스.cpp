// Include.h
/*
#include <vector>
#include <list>
#include <map>
#include <string>
#include <Windows.h>
#include <math.h>

using namespace std;

#include "Define.h"
#include "Structs.h"
#include "Enum.h"
*/

// Define.h
/*
extern HWND g_hWnd;

const int COUNT = 128;

#define WIDTH 1500
#define HEIGHT 900
*/

// Enum.h
/*
enum SCENEID {
	LOGO,
	MENU,
	STAGE,
};
*/

// Structs.h
/*
typedef struct tagVector3
{
	float x, y, z;

	tagVector3() : x(0), y(0), z(0) {}

	tagVector3(float _x, float _y) : x(_x), y(_y), z(0) {}

	tagVector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	tagVector3 operator+(tagVector3 vector)
	{
		return Vector3(
			x + vector.x,
			y + vector.y,
			z + vector.z);
	}

	tagVector3 operator-(tagVector3 vector)
	{
		return Vector3(
			x - vector.x,
			y - vector.y,
			z - vector.z);
	}

	tagVector3 operator+=(tagVector3 vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;

		return Vector3(x, y, z);
	}

	tagVector3 operator-=(tagVector3 vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;

		return Vector3(x, y, z);
	}

	tagVector3 operator*(float value)
	{
		return Vector3(
			x * value,
			y * value,
			z * value);
	}
}Vector3;

typedef struct tagTransform
{
	Vector3 position;
	Vector3 direction;
	Vector3 scale;

}Transform;
*/

// MainUpdate.h
/*
#include "Include.h"

class GameObject;
class MainUpdate
{
private :
	HDC m_hdc;
public:
	void Start();
	void Update();
	void Render();
	void Destroy();
public:
	MainUpdate();
	~MainUpdate();
};
*/

// MainUpdate.cpp
/*
#include "MainUpdate.h"
#include "SceneManager.h"

MainUpdate::MainUpdate()
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
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, WIDTH, HEIGHT);
	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Destroy()
{

}
*/

// GameObject.h
/*
#include "Include.h"

class GameObject
{
protected:
	Transform transform;
	float Speed;

	string Key;
public:
	virtual GameObject* Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	string GetKey() { return Key; }

	Transform GetTransform() { return transform; }
	//void SetTransform(Transform _transform) { transform = _transform; }

	Vector3 GetPosition() { return transform.position; }
	void SetPosition(Vector3 _position) { transform.position = _position; }

	Vector3 GetScale() { return transform.scale; }
	void SetScale(Vector3 _scale) { transform.scale = _scale; }
public:
	GameObject();
	virtual ~GameObject();
};
*/

// GameObject.cpp
/*
#include "GameObject.h"

GameObject::GameObject() : Speed(0.0f)
{

}

GameObject::~GameObject()
{

}
*/

// Player.h
/*
#include "GameObject.h"

class Player : public GameObject
{
private:

public:
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	GameObject* CreateBullet();
public:
	Player();
	virtual ~Player();
};
*/

// Player.cpp
/*
#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"

Player::Player()
{

}

Player::~Player()
{

}

GameObject* Player::Start()
{
	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(100.0f, 100.0f, 0.0f);

	Speed = 5.0f;

	return this;
}

int Player::Update()
{
	if (GetAsyncKeyState(VK_UP))
		transform.position.y -= Speed;

	if (GetAsyncKeyState(VK_DOWN))
		transform.position.y += Speed;

	if (GetAsyncKeyState(VK_LEFT))
		transform.position.x -= Speed;

	if (GetAsyncKeyState(VK_RIGHT))
		transform.position.x += Speed;

	if (GetAsyncKeyState(VK_SPACE))
	{
		ObjectManager::GetInstance()->AddObject(CreateBullet());
	}

	return 0;
}

void Player::Render(HDC hdc)
{
	Rectangle(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
}

void Player::Destroy()
{

}

GameObject* Player::CreateBullet()
{
	GameObject* bullet = new Bullet;
	bullet->Start();
	bullet->SetPosition(transform.position);

	return bullet;
}
*/

// Enemy.h
/*
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Enemy();
	virtual ~Enemy();
};
*/

// Enemy.cpp
/*
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

GameObject* Enemy::Start()
{
	srand((unsigned int)GetTickCount64());
	transform.position = Vector3(WIDTH + 75.0f, float(rand() % (HEIGHT - 150) + 75), 0.0f);
	transform.direction = Vector3(-1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(150.0f, 150.0f, 0.0f);

	Speed = 0.5f;
	Key = "Enemy";

	return this;
}

int Enemy::Update()
{
	transform.position += transform.direction * Speed;

	if (transform.position.x < 0)
		return 2;

	return 0;
}

void Enemy::Render(HDC hdc)
{
	Ellipse(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
}

void Enemy::Destroy()
{
}
*/

// Bullet.h
/*
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Bullet();
	virtual ~Bullet();
};
*/

// Bullet.cpp
/*
#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

GameObject* Bullet::Start()
{
	transform.position = Vector3(0.0f, 0.0f, 0.0f);
	transform.direction = Vector3(1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(30.0f, 30.0f, 0.0f);

	Speed = 15;
	Key = "Bullet";

	return this;
}

int Bullet::Update()
{
	transform.position += transform.direction * Speed;

	if (transform.position.x > WIDTH)
		return 1;

	return 0;
}

void Bullet::Render(HDC hdc)
{
	Ellipse(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
}

void Bullet::Destroy()
{
}
*/

// Scene.h
/*
#include "Include.h"

class Scene
{
public:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	Scene();
	virtual ~Scene();
};
*/

// Scene.cpp
/*
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}
*/

// Logo.h
/*
#include "Scene.h"

class Logo : public Scene
{
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Logo();
	virtual ~Logo();
};
*/

// Logo.cpp
/*
#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Start()
{
}

int Logo::Update()
{
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(MENU);

	return 0;
}

void Logo::Render(HDC hdc)
{
	Rectangle(hdc, 500, 500, 600, 600);
}

void Logo::Destroy()
{
}
*/

// Menu.h
/*
#include "Scene.h"

class Menu : public Scene
{
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Menu();
	virtual ~Menu();
};
*/

// Menu.cpp
/*
#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Start()
{
}

int Menu::Update()
{
	if (GetAsyncKeyState('S'))
		SceneManager::GetInstance()->SetScene(STAGE);

	return 0;
}

void Menu::Render(HDC hdc)
{
	Ellipse(hdc, 500, 500, 600, 600);
}

void Menu::Destroy()
{
}
*/

// Stage.h
/*
#include "Scene.h"

class GameObject;
class Stage : public Scene
{
private:
	GameObject* m_pPlayer;
	list<GameObject*>* EnemyList;
	list<GameObject*>* BulletList;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Stage();
	virtual ~Stage();
};
*/

// Stage.cpp
/*
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"

Stage::Stage() : m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	m_pPlayer = (new Player())->Start();
	//m_pPlayer->Start();

	ObjectManager::GetInstance()->AddObject((new Enemy)->Start());

	EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

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

	return 0;
}

void Stage::Render(HDC hdc)
{
	if (m_pPlayer)
		m_pPlayer->Render(hdc);

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
*/

// CollisionManager.h
/*
#include "Include.h"
#include "GameObject.h"

class CollisionManager
{
public:
	// 구(동그라미) 충돌
	static bool CircleCollision(GameObject* temp, GameObject* dest)
	{
		// x값과 y값을 구한다
		float fx = dest->GetPosition().x - temp->GetPosition().x;
		float fy = dest->GetPosition().y - temp->GetPosition().y;

		// 각각의 구의 반지름의 합을 구함
		float sum = dest->GetScale().x + temp->GetScale().x;

		// 거리를 구함
		float distance = sqrt((fx * fx) + (fy * fy));

		// 거리가 반지름의 합보다 작다면 충돌
		if (distance < sum)
			return true;

		return false;
	}

	// Rect 충돌
	static bool RectCollision(GameObject* temp, GameObject* dest)
	{
		// 각각의 Rect 상, 하, 좌, 우 좌표를 비교하여 충돌을 확인
		if (temp->GetPosition().x + (temp->GetScale().x * 0.5f) > dest->GetPosition().x - (dest->GetScale().x * 0.5f) &&
			dest->GetPosition().x + (dest->GetScale().x * 0.5f) > temp->GetPosition().x - (temp->GetScale().x * 0.5f) &&
			temp->GetPosition().y + (temp->GetScale().y * 0.5f) > dest->GetPosition().y - (dest->GetScale().y * 0.5f) &&
			dest->GetPosition().y + (dest->GetScale().y * 0.5f) > temp->GetPosition().y - (temp->GetScale().y * 0.5f))
			return true;
		return false;
	}
};
*/

// ObjectManager.h
/*
#include "Include.h"

class GameObject;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	map<string, list<GameObject*>> ObjectList;
public:
	void AddObject(GameObject* _Object);

	list<GameObject*>* GetObjectList(string key);
private:
	ObjectManager();
public:
	~ObjectManager();
};
*/

// ObjectManager.cpp
/*
#include "ObjectManager.h"
#include "GameObject.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::AddObject(GameObject* _Object)
{
	// 파라메터가 가르키고 있는 키 값이 현재 map에 포함되어 있는지 확인
	map<string, list<GameObject*>>::iterator iter = ObjectList.find(_Object->GetKey());

	// 만약 키가 없다면...
	if (iter == ObjectList.end())
	{
		// map에 포함시킬 list를 생성한 후...
		list<GameObject*> tempList;

		// 리스트에 오브젝트를 추가
		tempList.push_back(_Object);

		// 오브젝트가 추가된 리스트를 map에 추가
		ObjectList.insert(make_pair(_Object->GetKey(), tempList));
	}
	// 이미 키가 존재한다면...
	else
		// 해당 리스트에 오브젝트를 추가
		iter->second.push_back(_Object);
}

list<GameObject*>* ObjectManager::GetObjectList(string key)
{
	// 키 값이 현재 map에 포함되어 있는지 확인
	map<string, list<GameObject*>>::iterator iter = ObjectList.find(key);

	// 만약 키가 없다면...
	if (iter == ObjectList.end())
		// nullptr을 반환
		return nullptr;
	// 이미 키가 존재한다면...
	else
		// second = value = list<GameObject*>를 반환
		return &iter->second;
}
*/

// SceneManager.h
/*
#include "Include.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;
		return Instance;
	}
private:
	Scene* SceneState;
public:
	void SetScene(SCENEID _State);
	void Update();
	void Render(HDC hdc);
	void Destroy();
private:
	SceneManager();
public:
	~SceneManager();
};
*/

// SceneManager.cpp
/*
#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr)
{

}

SceneManager::~SceneManager()
{

}

void SceneManager::SetScene(SCENEID _State)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_State)
	{
	case LOGO:
		SceneState = new Logo;
		break;
	case MENU:
		SceneState = new Menu;
		break;
	case STAGE:
		SceneState = new Stage;
		break;
	default:
		break;
	}
	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render(HDC hdc)
{
	SceneState->Render(hdc);
}

void SceneManager::Destroy()
{
	delete SceneState;
	SceneState = nullptr;
}
*/