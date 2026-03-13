#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> menu =
{
	{500, 30},
	{300, 40},
	{700, 10},
	{400, 20},
	{600, 30},
};
int n;

int maxPoint = INT_MIN;
void DFS(int curLev, int start, int cost, int point)
{
	if (curLev == n)
	{
		int buyCount = 10000 / cost;
		int totalPoint = point * buyCount;

		if (totalPoint > maxPoint)
			maxPoint = totalPoint;

		return;
	}

	for (int i = start; i < menu.size(); ++i)
	{
		DFS(curLev + 1, i + 1, cost + menu[i][0], point + menu[i][1]);
	}
}


int main(void)
{
	cin >> n;

	DFS(0, 0, 0, 0);

	cout << maxPoint;

	return 0;
}