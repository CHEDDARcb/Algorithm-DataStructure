#include <iostream>

using namespace std;

struct Node
{
	char ch;
	Node* nxt;
};

Node buf[100];
int bufCnt;
Node* head;

Node* myAlloc(char ch, Node* nxt)
{
	buf[bufCnt].ch = ch;
	buf[bufCnt].nxt = nxt;
	return &buf[bufCnt++];
}

void addNode(char ch)
{
	head = myAlloc(ch, head);
}

int main(void)
{
	addNode('E');
	addNode('D');
	addNode('C');
	addNode('B');
	addNode('A');

	for (Node* i = head; i != nullptr; i = i->nxt)
	{
		cout << i->ch << " ";
	}

	return 0;
}