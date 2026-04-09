#include <iostream>
#include <vector>

using namespace std;

vector<int> blocks;
int n;
int maxBlockNum = INT_MIN;
const int MAX_BLOCK_SIZE = 100;

void DFS(int start, int size, int blockNum)
{
	if (size <= MAX_BLOCK_SIZE)
	{
		if (blockNum > maxBlockNum)
			maxBlockNum = blockNum;
	}

	for (int i = start; i < blocks.size(); ++i)
	{
		if (size + blocks[i] > MAX_BLOCK_SIZE)
			continue;

		DFS(i + 1, size + blocks[i], blockNum + 1);
	}
}

int main(void)
{
	cin >> n;

	blocks.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> blocks[i];

	DFS(0, 0, 0);

	cout << maxBlockNum;

	return 0;
}