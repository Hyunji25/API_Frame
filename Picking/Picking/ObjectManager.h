#pragma once
#include "Include.h"

class Object;
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

};

// 타일 누르면 다른색이 나오게 하는 과정

// 타일 이미지처럼 8칸 출력
// 128x64 -> 32x32