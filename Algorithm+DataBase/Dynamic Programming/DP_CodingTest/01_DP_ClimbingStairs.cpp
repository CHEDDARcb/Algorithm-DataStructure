#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

void MakeDPTable()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
}

int main(void)
{
	cin >> n;
	dp.resize(n + 1, 0);

	MakeDPTable();

	cout << dp[n];

	return 0;
}