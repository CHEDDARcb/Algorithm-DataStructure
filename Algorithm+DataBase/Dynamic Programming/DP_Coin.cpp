#include <iostream>
#include <vector>

using namespace std;

int main(void)
{

	// 동전 집합고 목표금액
	vector<int> coins = { 3, 4, 5 };
	int amount = 15;

	// DP테이블 초기화
	vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
	dp[0][0] = 1;

	static int callCount = 0;
	// 각 동전에 대해
	for (int i = 1; i <= coins.size(); ++i)
	{
		int coin = coins[i - 1];
		for (int j = 0; j <= amount; ++j)
		{
			cout << ++callCount << endl;

			if (j < coin)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - coin];
		}
	}

	cout << "DP테이블 (행: 동전개수, 열: 금액)" << endl;
	for (int i = 0; i <= coins.size(); ++i)
	{
		for (int j = 0; j <= amount; ++j)
			cout << dp[i][j] << " ";
		cout << endl;
	}

	cout << "\n" << amount << "원을 만드는 경우의 수: " << dp[coins.size()][amount] << endl;
}