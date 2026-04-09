#include <iostream>
#include <vector>

using namespace std;

long long fib(int n)
{
	if (n <= 1)
		return n;

	return fib(n - 1) + fib(n - 2);
}

vector<long long> memo;
long long fib_memo(int n)
{
	if (n <= 1)
		return n;

	if (memo[n] != 0)
		return memo[n];

	int left = fib_memo(n - 1);
	int right = fib_memo(n - 2);
	memo[n] = left + right;

	return memo[n];
}

long long fib_dp(int n)
{
	vector<long long> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}

int main(void)
{
	int prev = fib(4);

	int n = 4;
	memo.resize(n + 1);
	long long ans = fib_memo(n);
	ans = fib_memo(n);

	int dp = fib_dp(n);

	return 0;
}