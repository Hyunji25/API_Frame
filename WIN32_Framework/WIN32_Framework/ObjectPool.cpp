#include "ObjectPool.h"


ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
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