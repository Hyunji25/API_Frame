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

// Ÿ�� ������ �ٸ����� ������ �ϴ� ����

// Ÿ�� �̹���ó�� 8ĭ ���
// 128x64 -> 32x32