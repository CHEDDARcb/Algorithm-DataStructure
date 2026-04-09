#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int h = 0;
	vector<int> blocks;
};

int height;
int cnt = 0;
int cnt1 = 0;
int cnt2 = 0;
vector<vector<int>> results;
vector<int> h = { 1, 2 };
int callCnt = 0;
int maxLev = 0;
void DFS(Node node, int lev)
{
	++callCnt;
	if (lev > maxLev)
		maxLev = lev;

	if (node.h == height)
	{
		cnt++;
		results.push_back(node.blocks);

		if (node.blocks[0] == 1)
			cnt1++;
		else if (node.blocks[0] == 2)
			cnt2++;

		return;
	}

	for (int i = 0; i < h.size(); ++i)
	{
		if (node.h + h[i] > height)
			continue;

		node.blocks.push_back(h[i]);
		node.h += h[i];

		DFS(node, lev + 1);

		node.h -= h[i];
		node.blocks.pop_back();
	}
}

int main(void)
{
	cin >> height;

	DFS(Node{ 0 }, 0);

	for (int i = 0; i < results.size(); ++i)
	{
		for (int j = 0; j < results[i].size(); ++j)
		{
			cout << results[i][j] << " ";
		}

		cout << endl;
	}

	cout << "1start: " << cnt1 << endl;
	cout << "2start: " << cnt2 << endl;
	cout << "total: " << cnt << endl;
	cout << "callCount: " << callCnt << endl;
	cout << "MaxLevel: " << maxLev << endl;

	return 0;
}
