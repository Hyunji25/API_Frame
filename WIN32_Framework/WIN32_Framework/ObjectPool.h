#pragma once
#include "Include.h"

class GameObject;
class ObjectPool
{
public:
	Single(ObjectPool)
private:
	list<GameObject*> PoolList;
public:
	list<GameObject*>* GetLost() { return &PoolList; }
	GameObject* GetPoolObject();
	void ReturnObject(GameObject* _Object);
private:
	ObjectPool();
public:
	~ObjectPool();
};
