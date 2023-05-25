#include "ObjectPool.h"
#include "GameObject.h"

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}

void ObjectPool::ReturnObject(GameObject* _Object)
{
	// ** 파라메터가 가르키고있는 키 값이 현재 map에 포함되어있는지 확인.
	map<string, list<GameObject*>>::iterator iter = PoolList.find(_Object->GetKey());

	// ** 만약 키가 없다면....
	if (iter == PoolList.end())
	{
		// ** map에 포함시킬 list를 생성한후...
		list<GameObject*> tempList;

		// ** 리스트에 오브젝트를 추가.
		tempList.push_back(_Object);

		// ** 오브젝트가 추가된 리스트를 map에 추가.
		PoolList.insert(make_pair(_Object->GetKey(), tempList));
	}
	// ** 이미 키가 존재 한다면....
	else
		// ** 해당 리스트에 오브젝트를 추가.
		iter->second.push_back(_Object);
}


/*
에너미랑 불렛이 충돌되었는지 확인하고
충돌이면 불렛이 스스로 destroy 호출하고
호출되면 오브젝트풀에 리턴오브젝트 함수 호출하고
호출하면 풀리스트로 들어가도록
*/