#include <iostream>
#include <Windows.h>

using namespace std;

void SetCorsorPosition(const float& _x, const float& _y);

int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "¦£¦¡¦¤" << endl;
		cout << "¦¢  ¦¢" << endl;
		cout << "¦¦¦¡¦¥" << endl;
	}
	
	return 0;
}

void SetCorsorPosition(const float& _x, const float& _y)
{
	COORD pos = { _x,_y };

	SetConsoleCursorPosition(GetStdHandle())
}