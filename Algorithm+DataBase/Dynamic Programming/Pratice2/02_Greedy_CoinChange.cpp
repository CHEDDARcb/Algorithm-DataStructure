#include <iostream>
#include <vector>

using namespace std;

const vector<int> coins = { 10, 50, 100, 500 };
int amount;

int main(void)
{
	cin >> amount;

	vector<int> coinCount(coins.size(), 0);

	for (int i = coins.size() - 1; i >= 0; --i)
	{
		if (amount < coins[i])
			continue;

		int coinNum = amount / coins[i];
		amount -= coinNum * coins[i];
		coinCount[i] += coinNum;

	}

	int coinNum = 0;
	for (int i = 0; i < coinCount.size(); ++i)
	{
		coinNum += coinCount[i];
	}

	cout << coinNum;

	return 0;
}