#include <iostream>
#include <vector>

using namespace std;

struct Data
{
	char company;
	int id;
};

const vector<Data> schedule =
{
	{'A', 21},
	{'E', 15},
	{'E', 6},
	{'A', 15},
	{'E', 34},
	{'B', 32},
	{'C', 35},
	{'C', 36},
	{'D', 14},
	{'A', 3},
};

struct Node
{
	int id;
	Node* nxt;
};
Node buff[100];
int bufSize = 0;
Node* hsh[5];

Node* Allc(int id)
{
	buff[bufSize].id = id;
	buff[bufSize].nxt = nullptr;

	return &buff[bufSize++];
}

void Push(int idx, int id)
{
	Node* newNode = Allc(id);

	if (hsh[idx] == nullptr)
	{
		hsh[idx] = newNode;
		return;
	}

	Node* cur = hsh[idx];
	while (cur->nxt != nullptr)
	{
		cur = cur->nxt;
	}
	cur->nxt = newNode;
}
int main(void)
{
	for (int i = 0; i < schedule.size(); ++i)
	{
		int idx = schedule[i].company - 'A';
		Push(idx, schedule[i].id);
	}

	char input;
	cin >> input;

	Node* cur = hsh[input - 'A'];
	while (cur != nullptr)
	{
		cout << cur->id << " ";
		cur = cur->nxt;
	}

	return 0;
}