#include <iostream>

using namespace std;

// -------------------------------------- 230510

// 1. 함수 사용
// 2. 클래스의 이해도

// for(초기문; 조건문; 증감문)
// ** 초기문 : int i = 0;
// ** 조건문 : i < 10;
// ** 증감문 : ++i

// return 0 : 정상 종료
// return -1 : 오류

// Singleton Instance
/*
#define function(x) (cout << x << endl)

#define Single(T)						\
public:											\
	static T& GetInstance()	\
	{												\
		static T Instance;			\
		return Instance;				\
	}												\
private:										\
	T(const T&) = delete;			\
	T& operator=(const T&) = delete;

#define GetSingle(T) (T::GetInstance())

class Singleton
{
public:
	Single(Singleton)
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

int main(void)
{
	GetSingle(Singleton).SetValue(10);
	cout << GetSingle(Singleton).GetValue() << endl;

	return 0;
}
*/

// -------------------------------------- 230511, 230512, 230516
/*
template <typename T>
class Node
{
private:
	Node* next;
	int value;

	Node* end;
public:
	void Push(int value)
	{

		Node* node = next;

		while (node != nullptr)
			node = node->next;

		node = new Node;
		node->value = value;
		next->next = node;



		end = new Node;
		end->value = value;
		next = end;

		end = next->next;
	}
public:
	Node() : next(nullptr), value(0), endl(next) {}
	~Node() {}
};
*/

typedef struct tagNode
{
	tagNode* next;
	int value;
}NODE;

NODE* List;
NODE* End;
int Length;

void push(int value)
{
	// ** create
	NODE* node = new NODE;

	// ** initialize
	node->next = nullptr;
	node->value = value;

	End->next = node;
	End = node;
	++Length;
}

void pop()
{
	if (Length < 1)
		return;
	else if (Length < 2)
	{
		delete List->next;
		List->next = nullptr;
		End = List;
	}
	else
	{
		// ** 리스트를 들고 옴
		NODE* nextLode = List;

		while (nextLode->next->next != nullptr)
		{
			// ** 다음 노드로 이동
			nextLode = nextLode->next;
		}

		End = nextLode;
		delete nextLode->next;
		nextLode->next = nullptr;
	}
	--Length;
}

void insert(int count, int value)
{
	// ** 리스트의 담긴 총 원소의 개수보다 count의 값이 크다면 
	// ** 값을 추가할 수 없으므로 종료
	if (Length < count)
		return;

	// ** 리스트를 들고 옴
	NODE* nextNode = List;

	// ** 카운트의 값만큼 다음 노드로 이동
	while (0 < count)
	{
		--count;

		// ** 다음 노드로 이동
		nextNode = nextNode->next;
	}
	// ** 이동이 끝났다면 새로운 노드를 추가

	// ** 새로운 노드 생성
	NODE* newNode = new NODE;
	newNode->next = nullptr;
	newNode->value = value;

	// ** 다음 노드를 임시의 저장소에 저장
	NODE* tempNode = nextNode->next;

	// ** 다음 노드를 저장하는 저장소에 새로운 노드를 배치
	nextNode->next = newNode;

	// ** 새로운 노드가 가르키는 다음 노드를 임시 공간에 있던 노드로 배치 
	newNode->next = tempNode;
}

void remove(int count)
{
	// ** 리스트의 담긴 총 원소의 개수보다 count의 값이 크다면 
	// ** 값을 추가할 수 없으므로 종료
	if (Length < count)
		return;

	// ** 리스트를 들고 옴
	NODE* nextNode = List;
	NODE* oldNode = nullptr;

	// ** 카운트의 값만큼 다음 노드로 이동
	while (0 < count)
	{
		--count;

		// ** 다음 노드로 이동
		nextNode = nextNode->next;
	}

	// ** 다음 노드를 임시의 저장소에 저장
	NODE* tempNode = nextNode->next->next;

	// ** 다음 노드를 삭제
	delete nextNode->next;
	nextNode->next = nullptr;

	// ** 삭제된 공간에 임시 저장했던 노드를 세팅
	nextNode->next = tempNode;
}

int main(void)
{
	// ** 첫번째 노드
	// create
	List = new NODE;

	// initialize
	List->next = nullptr;
	List->value = 0;

	End = List;

	// ** 두번째 노드
	push(10);
	push(20);
	push(30);
	push(40);

	insert(2, 25);
	remove(2);

	pop();

	push(100);
	push(200);

	// ** 두번째 노드를 nextNode에 넘겨준다
	NODE* nextNode = List->next;

	// ** nextNode가 nullptr이 아니라면 반복
	while (nextNode != nullptr)
	{
		// ** 출력
		cout << nextNode->value << endl;

		// ** 다음 노드로 이동
		nextNode = nextNode->next;
	}
	return 0;
}

// -------------------------------------- 230512

/*
int main(void)
{
	int i = 10;
	int* n = &i;

	cout << i << endl;
	cout << *n << endl;

	cout << &i << endl;
	cout << n << endl;

	*n = 20;
	cout << i << endl;
}
*/