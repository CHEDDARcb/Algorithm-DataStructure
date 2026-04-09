#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	char code;
	int killCount;
	Node* next;
};

Node buff[100];
int bufSize = 0;
Node* hsh[26];

Node* Allc(char c, int kc, Node* nxt)
{
	buff[bufSize].code = c;
	buff[bufSize].killCount = kc;
	buff[bufSize].next = nxt;

	return &buff[bufSize++];
}

void Insert(char c, int kc)
{
	int idx = c - 'A';
	hsh[idx] = Allc(c, kc, hsh[idx]);
}

int main(void)
{
	Insert('B', 10);
	Insert('B', 11);
	Insert('Z', 16);

	char input;
	cin >> input;

	Node* cur = hsh[input - 'A'];
	while (cur != nullptr)
	{
		cout << cur->killCount << " ";
		cur = cur->next;
	}

	return 0;
}