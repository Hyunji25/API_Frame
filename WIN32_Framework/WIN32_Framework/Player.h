#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	GameObject* BulletList[16];
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	GameObject* CreateBullet();
public:
	Player();
	virtual ~Player();
};

