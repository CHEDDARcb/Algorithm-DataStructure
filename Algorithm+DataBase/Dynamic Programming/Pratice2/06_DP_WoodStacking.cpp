#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
int height;
const int oneStart = 0;
const int twoStart = 1;
const int total = 2;

void Init()
{
	cin >> height;

	dp.resize(3, vector<int>(height, 0));
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[2][0] = 1;
}

void MakeDPTable()
{
	for (int i = 1; i < height; ++i)
	{
		dp[oneStart][i] = dp[total][i - 1];
		dp[twoStart][i] = dp[oneStart][i - 1];
		dp[total][i] =
			dp[oneStart][i] + dp[twoStart][i];
	}
}

int main(void)
{
	Init();

	MakeDPTable();

	cout << dp[total][height - 1];

	return 0;
}