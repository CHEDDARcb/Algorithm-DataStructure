#include <iostream>
#include <vector>

using namespace std;

const vector<int> coins = { 10, 50, 100, 500 };
int amount;
bool**** visited;

void Init()
{
	cin >> amount;

	int size = amount / coins[0] + 1;
	visited = new bool*** [size];
	for (int i = 0; i < size; ++i)
	{
		visited[i] = new bool** [size];
		for (int j = 0; j < size; ++j)
		{
			visited[i][j] = new bool* [size];
			for (int z = 0; z < size; ++z)
			{
				visited[i][j][z] = new bool[size];
			}
		}
	}

	for (int k = 0; k < size; ++k)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				for (int z = 0; z < size; ++z)
					visited[k][i][j][z] = false;
			}
		}
	}
}

int minCoinNum = INT_MAX;
void DFS(int sum, int coinCount, vector<int> coinNum)
{

	if (sum == amount)
	{
		if (minCoinNum > coinCount)
			minCoinNum = coinCount;
		return;
	}

	for (int i = 0; i < coins.size(); ++i)
	{
		++coinNum[i];
		int c1 = coinNum[0];
		int c2 = coinNum[1];
		int c3 = coinNum[2];
		int c4 = coinNum[3];

		if (visited[c1][c2][c3][c4])
			continue;

		if (sum + coins[i] > amount)
			continue;

		
		visited[c1][c2][c3][c4] = true;
		DFS(sum + coins[i], coinCount + 1, coinNum);


		--coinNum[i];
	}

}

int main(void)
{
	Init();

	DFS(0, 0, vector<int>{0, 0, 0, 0});

	cout << minCoinNum;

	return 0;
}