#include <iostream>
#include <vector>

using namespace std;

int* Numbers = nullptr;
int Length = 0;
int Size;
int Capacity;

void push(int n)
{
	if (Numbers == nullptr)
	{
		Numbers = new int;
		*Numbers = n;
		++Length;
		return;
	}
	
	int* Temp = new int[Length + 1];

	for (int i = 0; i < Length; ++i)
		Temp[i] = Numbers[i];

	Temp[Length] = n;
	Numbers = Temp;
	++Length;
}

void push_back(int _value)
{
	if (Size == Capacity)
	{
		int Length = int(Capacity * 0.5f);
		Capacity += Length < 1 ? 1 : Length;
	}

	int* temp = new int[Capacity];

	for (int i = 0; i < Size; ++i)
		temp[i] = Numbers[i];

	delete Numbers;
	Numbers = nullptr;

	Numbers = temp;

	
	for (int i = 0; i < Size; ++i)
		Numbers[i] = temp[i];

	Numbers[Size] = _value;

	++Size;
}

void pop_back()
{
	--Size;
}

// 위치가 사이즈보다 크면x, 수용량이 사이즈보다 크면x
void insert(int _where, int _value)
{
	if (_where > Size)
		return;

	++Size;

	if (Size == Capacity)
	{
		int Length = int(Capacity * 0.5f);
		Capacity += Length < 1 ? 1 : Length;
	}

	for (int i = Size - 1; i > _where; --i)
	{
		Numbers[i + 1] = Numbers[i];
	}

	Numbers[_where - 1] = _value;
}

int main(void)
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	for (int i = 0; i < Length; ++i)
	{
		cout << Numbers[i] << endl;
	}

	cout << endl;

	vector<int> vecList;

	for (int i = 0; i < 5; ++i)
	{
		vecList.push_back(i * 10 + 10);

		cout << vecList.capacity() << endl;
		cout << vecList[i] << endl;
	}

	/*
	vector<int> temp;

	for (int i = 0; i < 10; ++i)
	{
		temp.push_back(i * 10 + 10);

		cout << temp[i] << endl;
		cout << "size : " << temp.size() << endl;
		cout << "capacity : " << temp.capacity() << endl;
	}
	/

	for (int i = 0; i < 10; ++i)
	{
		push_back(i 10 + 10);
		cout << "Size : " << Size << endl;
		cout << "Capacity : " << Capacity << endl;
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << Numbers[i] << endl;
	}
*/

	return 0;
}

