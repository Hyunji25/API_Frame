#pragma once
#include "Include.h"

//class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;
public:
	//Single(SceneManager)
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;
		return Instance;
	}
private:
	//Scene* SceneState;
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

