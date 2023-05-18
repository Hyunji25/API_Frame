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

void insert(int _where, int _value)
{
	if (_where > Size)
		return;

	if (Size == Capacity)
	{
		int Length = int(Capacity * 0.5f);
		Capacity += Length < 1 ? 1 : Length;
	}
	
	_where -= 1;

	for (int i = Size; _where <= i ; --i)
		Numbers[i + 1] = Numbers[i];

	Numbers[_where] = _value;
	++Size;
}

void erase(int _where)
{
	if (_where > Size || _where <= 0)
		return;

	--Size;
	--_where;

	for (int i = _where; i < Size; ++i)
		Numbers[i] = Numbers[i + 1];
}

int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		push_back(i * 10 + 10);
		cout << "Size : " << Size << endl;
		cout << "Capacity : " << Capacity << endl << endl;
	}

	insert(6, 55);

	erase(2);

	for (int i = 0; i < Size; ++i)
	{
		cout << Numbers[i] << endl;
	}
	cout << "Size : " << Size << endl;
	return 0;
}

