#pragma once

extern HWND g_hWnd;


const int COUNT = 128;


#define WIDTH 740
#define HEIGHT 986


const int KEYID_UP = 0x00000001;
const int KEYID_DOWN = 0x00000002;
const int KEYID_LEFT = 0x00000004;
const int KEYID_RIGHT = 0x00000008;
const int KEYID_RETURN = 0x00000010;
const int KEYID_SPACE = 0x00000020;
const int KEYID_ESCAPE = 0x00000040;
const int KEYID_CONTROL = 0x00000080;

const int STATEID_HIT = 0x00000001;
const int STATEID_ATTACK = 0x00000002;
const int STATEID_JUMP = 0x00000004;


#define Single(T)					\
public:								\
	static T** GetInstance()		\
	{								\
		static T* instance;			\
		if(instance == nullptr)		\
			instance = new T;		\
		return &instance;			\
	}								\
private:							\
	T(const T&) = delete;			\
	T& operator=(const T&) = delete;

#define GetSingle(T) (*T::GetInstance())

//GetSingle(Singleton).SetValue(10);
// cout << GetSingle(Singleton).GetValue() << endl;

/*
class Singleton
{
public:
	Single(Singleton)

------------------------------------x
private:
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;

		return Instance;
	}
------------------------------------x

private:
	int Value;
public:
	int GetValue() { return Value; }
	void SetValue(int value) { Value = value; }
private:
	Singleton() : Value(0) {}
public:
	~Singleton() {}
};
*/