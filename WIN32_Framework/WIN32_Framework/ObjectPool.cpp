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
에너미랑 불렛이 충돌되었는지 확인하고
충돌이면 불렛이 스스로 destroy 호출하고
호출되면 오브젝트풀에 리턴오브젝트 함수 호출하고
호출하면 풀리스트로 들어가도록
*/