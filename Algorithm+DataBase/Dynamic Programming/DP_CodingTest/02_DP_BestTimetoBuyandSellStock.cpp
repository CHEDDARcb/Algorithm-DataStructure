#include <iostream>
#include <vector>

using namespace std;

vector<int> prices;

int main(void)
{
	prices.resize(6);

	for (int i = 0; i < 6; ++i)
		cin >> prices[i];

	int minPrice = prices[0];
	int maxProfit = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		if (minPrice > prices[i])
			minPrice = prices[i];
		else if (prices[i] - minPrice > maxProfit)
			maxProfit = prices[i] - minPrice;
	}

	cout << maxProfit;

	return 0;
}