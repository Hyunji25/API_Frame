#include "ObjectPool.h"


ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}

GameObject* ObjectPool::GetPoolObject()
{
	GameObject* Obj = PoolList.pop_back();
	return nullptr;
}

void ObjectPool::ReturnObject(GameObject* _Object)
{
	PoolList.push_back(_Object);
}


/*
���ʹ̶� �ҷ��� �浹�Ǿ����� Ȯ���ϰ�
�浹�̸� �ҷ��� ������ destroy ȣ���ϰ�
ȣ��Ǹ� ������ƮǮ�� ���Ͽ�����Ʈ �Լ� ȣ���ϰ�
ȣ���ϸ� Ǯ����Ʈ�� ������
*/