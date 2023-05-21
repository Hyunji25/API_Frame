#include <iostream>

using namespace std;

// -------------------------------------- 230510

// 1. �Լ� ���
// 2. Ŭ������ ���ص�

// for(�ʱ⹮; ���ǹ�; ������)
// ** �ʱ⹮ : int i = 0;
// ** ���ǹ� : i < 10;
// ** ������ : ++i

// return 0 : ���� ����
// return -1 : ����

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
		// ** ����Ʈ�� ��� ��
		NODE* nextLode = List;

		while (nextLode->next->next != nullptr)
		{
			// ** ���� ���� �̵�
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
	// ** ����Ʈ�� ��� �� ������ �������� count�� ���� ũ�ٸ� 
	// ** ���� �߰��� �� �����Ƿ� ����
	if (Length < count)
		return;

	// ** ����Ʈ�� ��� ��
	NODE* nextNode = List;

	// ** ī��Ʈ�� ����ŭ ���� ���� �̵�
	while (0 < count)
	{
		--count;

		// ** ���� ���� �̵�
		nextNode = nextNode->next;
	}
	// ** �̵��� �����ٸ� ���ο� ��带 �߰�

	// ** ���ο� ��� ����
	NODE* newNode = new NODE;
	newNode->next = nullptr;
	newNode->value = value;

	// ** ���� ��带 �ӽ��� ����ҿ� ����
	NODE* tempNode = nextNode->next;

	// ** ���� ��带 �����ϴ� ����ҿ� ���ο� ��带 ��ġ
	nextNode->next = newNode;

	// ** ���ο� ��尡 ����Ű�� ���� ��带 �ӽ� ������ �ִ� ���� ��ġ 
	newNode->next = tempNode;
}

void remove(int count)
{
	// ** ����Ʈ�� ��� �� ������ �������� count�� ���� ũ�ٸ� 
	// ** ���� �߰��� �� �����Ƿ� ����
	if (Length < count)
		return;

	// ** ����Ʈ�� ��� ��
	NODE* nextNode = List;
	NODE* oldNode = nullptr;

	// ** ī��Ʈ�� ����ŭ ���� ���� �̵�
	while (0 < count)
	{
		--count;

		// ** ���� ���� �̵�
		nextNode = nextNode->next;
	}

	// ** ���� ��带 �ӽ��� ����ҿ� ����
	NODE* tempNode = nextNode->next->next;

	// ** ���� ��带 ����
	delete nextNode->next;
	nextNode->next = nullptr;

	// ** ������ ������ �ӽ� �����ߴ� ��带 ����
	nextNode->next = tempNode;
}

int main(void)
{
	// ** ù��° ���
	// create
	List = new NODE;

	// initialize
	List->next = nullptr;
	List->value = 0;

	End = List;

	// ** �ι�° ���
	push(10);
	push(20);
	push(30);
	push(40);

	insert(2, 25);
	remove(2);

	pop();

	push(100);
	push(200);

	// ** �ι�° ��带 nextNode�� �Ѱ��ش�
	NODE* nextNode = List->next;

	// ** nextNode�� nullptr�� �ƴ϶�� �ݺ�
	while (nextNode != nullptr)
	{
		// ** ���
		cout << nextNode->value << endl;

		// ** ���� ���� �̵�
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