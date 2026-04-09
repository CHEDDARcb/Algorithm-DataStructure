#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* nxt;
};

void Push(Node** head, Node** tail, char data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->nxt = nullptr;

	if (*head == nullptr)
	{
		*head = newNode;
		*tail = newNode;
		return;
	}

	(*tail)->nxt = newNode;
	*tail = newNode;
}

char Pop(Node** head, Node** tail)
{
	if (*head == nullptr)
		return '!';

	if (*head == *tail)
		*tail = nullptr;

	char popData = (*head)->data;
	Node* nxt = (*head)->nxt;
	delete* head;
	*head = nxt;

	return popData;
}

int main(void)
{
	Node* head = nullptr;
	Node* tail = nullptr;

	for (char d = 'A'; d <= 'E'; ++d)
	{
		Push(&head, &tail, d);
	}

	for (int i = 'A'; i <= 'E'; ++i)
	{
		cout << Pop(&head, &tail);
	}

	return 0;
}