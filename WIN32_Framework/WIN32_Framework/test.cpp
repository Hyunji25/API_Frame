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

// Structs.h
/*
typedef struct tagVector3
{
	float x, y, z;

	tagVector3() : x(0), y(0), z(0) {}

	tagVector3(float _x, float _y) : x(_x), y(_y), z(0) {}

	tagVector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
}Vector3;

typedef struct tagTransform
{
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
}Transform;
*/

// WIN32_Framework.cpp
/*
MSG msg;
    msg.message = NULL;

    // 기본 메시지 루프입니다:

    MainUpdate Main;
    Main.Start();

    ULONGLONG Time = GetTickCount64();

    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            if (Time < GetTickCount64())
            {
                Time = GetTickCount64();

                Main.Update();
                Main.Render();
            }
        }
    }
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
    virtual void Start(Vector3 _position)PURE;
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
    virtual void Start(Vector3 _position)override {}
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
    transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
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
    bullet->Start(transform.position);

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
    virtual void Start(Vector3 _position)override {}
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
    transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
    transform.scale = Vector3(150.0f, 150.0f, 0.0f);

    Speed = 0.5f;
    Key = "Enemy";

    return this;
}

int Enemy::Update()
{
    transform.position.x -= Speed;

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
    virtual void Start(Vector3 _position)override;
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
    transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
    transform.scale = Vector3(30.0f, 30.0f, 0.0f);

    Speed = 15;
    Key = "Bullet";

    return this;
}

void Bullet::Start(Vector3 _position)
{
    transform.position = Vector3(_position);
    transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
    transform.scale = Vector3(30.0f, 30.0f, 0.0f);

    Speed = 15;
    Key = "Bullet";
}

int Bullet::Update()
{
    transform.position.x += Speed;

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

    ObjectManager::GetInstance()->AddObject((new Enemy)->Start());
}

int Stage::Update()
{
    if (m_pPlayer)
        m_pPlayer->Update();

    return 0;
}

void Stage::Render(HDC hdc)
{
    list<GameObject*>* EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
    list<GameObject*>* BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");

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
