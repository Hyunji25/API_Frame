#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Prototype.h"
#include "ObjectPool.h"

#include "NormalBullet.h"
#include "GuideBullet.h"
#include "Bitmap.h"

Player::Player()
{

}

Player::~Player()
{

}

GameObject* Player::Start()
{
	frame.CountX = 0;
	frame.CountY = 0;
	frame.EndFrame = 7;
	frame.FrameTime = 50;

	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(676 / 7, 639 / 9, 0.0f);

	Speed = 5.0f;

	Key = "Player";

	Time = GetTickCount64();
	return this;
}

int Player::Update()
{
	DWORD dwKey = GetSingle(InputManager)->GetKey();

	if (Time + frame.FrameTime < GetTickCount64())
	{
		Time = GetTickCount64();
		++frame.CountX;

		if (frame.CountX >= frame.EndFrame)
			frame.CountX = 0;

		if (dwKey & (KEYID_UP | KEYID_DOWN | KEYID_LEFT | KEYID_RIGHT))
		{
			frame.CountY = 1;
			frame.EndFrame = 3;
		}
		else if (dwKey & (KEYID_SPACE | KEYID_CONTROL))
		{
			frame.CountY = 5;
			frame.EndFrame = 4;
		}
		else if (GetAsyncKeyState(VK_LSHIFT))
		{
			frame.CountY = 4;
			frame.EndFrame = 2;
		}
		else
		{
			frame.CountY = 0;
			frame.EndFrame = 7;
		}
	}

	if (dwKey & KEYID_UP)
		transform.position.y -= Speed;

	if (dwKey & KEYID_DOWN)
		transform.position.y += Speed;

	if (dwKey & KEYID_LEFT)
		transform.position.x -= Speed;

	if (dwKey & KEYID_RIGHT)
		transform.position.x += Speed;

	if (dwKey & KEYID_SPACE)
		ObjectManager::GetInstance()->AddObject(CreateBullet<NormalBullet>("NormalBullet"));

	if (dwKey & KEYID_CONTROL)
		ObjectManager::GetInstance()->AddObject(CreateBullet<GuideBullet>("GuideBullet"));

	if (GetAsyncKeyState(VK_LSHIFT))
		transform.position.x += Speed * 2;
	return 0;
}

void Player::Render(HDC hdc)
{
	TransparentBlt(hdc,	  // ������ ���� �׸��� ?!
		(int)transform.position.x,	// ������ ���� ������ X
		(int)transform.position.y, 	// ������ ���� ������ Y
		(int)transform.scale.x,	// ������ ���� ���κ� X
		(int)transform.scale.y, 	// ������ ���� ���κ� Y
		(*m_ImageList)[Key]->GetMemDC(),	// ������ �̹��� (������)
		transform.scale.x * frame.CountX,  // ������ ������ X
		transform.scale.y * frame.CountY,	// ������ ������ Y
		(int)transform.scale.x, 			// ����� �̹����� ũ�� ��ŭ X
		(int)transform.scale.y,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));		// �ش� ������ ����
}

void Player::Destroy()
{

}

template <typename T>
GameObject* Player::CreateBullet(string _Key)
{
	GameObject* Obj = GetSingle(ObjectPool)->GetGameObject(_Key);

	if (Obj == nullptr)
	{
		Bridge* pBridge = new T;
		pBridge->Start();
		((BulletBridge*)pBridge)->SetTarget(this);

		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject(_Key);

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			Object->Start();
			Object->SetPosition(transform.position);
			Object->SetKey(_Key);

			pBridge->SetObject(Object);
			Object->SetBridge(pBridge);

			return Object;
		}
		else
			return nullptr;
	}

	Obj->Start();
	Obj->SetPosition(transform.position);
	Obj->SetKey(_Key);

	return Obj;
}