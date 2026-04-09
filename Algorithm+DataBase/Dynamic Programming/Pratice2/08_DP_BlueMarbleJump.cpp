#include <iostream>
#include <vector>

using namespace std;

///0 2 4 -5 -7 6 20 7 -10 -8  4 -1
const int MAP_SIZE = 12;
vector<int> map(MAP_SIZE, 0);
vector<int> dp(MAP_SIZE, 0);

vector<bool> reachable(MAP_SIZE, false);

void Init()
{
	for (int i = 0; i < map.size(); ++i)
		cin >> map[i];

	dp[0] = 0;
	reachable[0] = true;
}

void MakeDPTable()
{
	for (int i = 1; i < dp.size(); ++i)
	{
		bool canReach = false;

		int moved2 = INT_MIN;
		if (i - 2 >= 0 && reachable[i - 2])
		{
			moved2 = dp[i - 2] + map[i];
			canReach = true;
		}

		int moved3 = INT_MIN;
		if (i - 3 >= 0 && reachable[i - 3])
		{
			moved3 = dp[i - 3] + map[i];
			canReach = true;
		}

		int movedMulti = INT_MIN;
		if (i % 2 == 0 && reachable[i / 2])
		{
			movedMulti = dp[i / 2] + map[i];
			canReach = true;
		}

		if(canReach)
		{
			dp[i] = max(max(moved2, moved3), movedMulti);
			reachable[i] = true;
		}
	}
}

int main(void)
{
	Init();
	MakeDPTable();

	int mx = INT_MIN;
	for (int i = MAP_SIZE / 2; i < dp.size(); ++i)
	{
		if (mx < dp[i])
			mx = dp[i];
	}

	cout << mx;

	return 0;
}