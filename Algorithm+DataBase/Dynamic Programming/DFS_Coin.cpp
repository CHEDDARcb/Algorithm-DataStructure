#include <iostream>
#include <vector>

using namespace std;

const vector<int> coins = { 3, 4, 5 };
const int amount = 12;

int cnt = 0;

static int callCount = 0;
void DFS(int idx, int sum, int lev)
{
	cout << ++callCount << endl;
	if (sum == amount)
	{
		++cnt;
		return;
	}

	if (sum > amount || idx >= coins.size())
		return;

	DFS(idx, sum + coins[idx], lev + 1);
	DFS(idx + 1, sum + coins[idx], lev + 1);
}

int main(void)
{
	DFS(0, 0, 0);

	cout << cnt;

	return 0;
}