#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* nxt;
};
Node buf[100];
Node* head = nullptr;
int bufSize = 0;

void AddData(int d)
{
	buf[bufSize].data = d;
	buf[bufSize].nxt = nullptr;

	if (bufSize == 0)
	{
		head = &buf[bufSize];
	}
	else if (bufSize > 0)
	{
		buf[bufSize - 1].nxt = &buf[bufSize];
	}
	++bufSize;
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int d;
		cin >> d;
		AddData(d);
	}

	for (Node* cur = head; cur != nullptr; cur = cur->nxt)
	{
		cout << cur->data << " ";
	}

	return 0;
}