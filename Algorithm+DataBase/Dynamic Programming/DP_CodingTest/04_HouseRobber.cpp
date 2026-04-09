#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> houses = { 1, 3, 1, 3, 100 };
	//vector<int> houses = { 6, 7, 1, 30, 8, 2, 4 };
	vector<int> dp(houses.size(), 0);

	if (houses.size() == 1)
	{
		cout << houses[0];
		return 0;
	}
	else if (houses.size() == 2)
	{
		cout << max(houses[0], houses[1]);
		return 0;
	}

	dp[0] = houses[0];
	dp[1] = houses[1];
	dp[2] = houses[0] + houses[2];

	int mx = max(dp[1], dp[2]);

	if (houses.size() == 3)
	{
		cout << mx;
		return 0;
	}

	for(int i = 3; i < houses.size(); ++i)
	{
		int prev2 = dp[i - 2];
		int prev3 = dp[i - 3];
		int prev = max(prev2, prev3);

		dp[i] = houses[i] + prev;

		if (dp[i] > mx)
			mx = dp[i];
	}

	cout << mx;

	return 0;
}