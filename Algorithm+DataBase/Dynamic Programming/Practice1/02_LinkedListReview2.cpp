#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* next;
};
Node* head = nullptr;
Node buf[100];
int bufSize = 0;
const int INPUTNUM = 9;

Node* MyAlloc(char d, Node* nxt)
{
	buf[bufSize].data = d;
	buf[bufSize].next = nxt;

	return &buf[bufSize++];
}

void AddData(char d)
{
	head = MyAlloc(d, head);
}

int main(void)
{
	for (int k = 0; k < INPUTNUM; ++k)\
	{
		char c;
		cin >> c;

		AddData(c);
	}

	Node* cur = head;
	while (cur)
	{
		cout << cur->data;

		if (cur->next == nullptr )
			break;
		cur = cur->next->next;
	}

	return 0;
}