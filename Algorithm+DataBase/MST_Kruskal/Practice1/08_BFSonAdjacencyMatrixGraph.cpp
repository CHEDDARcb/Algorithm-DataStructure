#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<int> names =
{ 1, 2, 3, 4, 6, 7, 8, 9 };
const vector<vector<int>> map =
{
	// 1  2  3  4  6  7  8  9 
	  {0, 0, 1, 1, 0, 0, 1, 0},
	  {0, 0, 0, 0, 1, 1, 0, 1},
	  {1, 0, 0, 0, 1, 0, 1, 0},
	  {1, 0, 0, 0, 0, 1, 1, 0},
	  {0, 1, 1, 0, 0, 0, 0, 1},
	  {0, 1, 0, 1, 0, 0, 1, 1},
	  {1, 0, 1, 1, 0, 1, 0, 0},
	  {0, 1, 0, 0, 1, 1, 0, 0}
};
vector<bool> pushed(map.size(), false);

void BFS(int i)
{
	queue<int> que;
	que.push(i);
	pushed[i] = true;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		cout << names[cur] << " ";

		for (int i = 0; i < map[cur].size(); ++i)
		{
			if (map[cur][i] == 0 ||
				pushed[i])
				continue;

			que.push(i);
			pushed[i] = true;
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	int s;
	if (n == 1) s = 0;
	else if (n == 2) s = 1;
	else if (n == 3) s = 2;
	else if (n == 4) s = 3;
	else if (n == 6) s = 4;
	else if (n == 7) s = 5;
	else if (n == 8) s = 6;
	else if (n == 9) s = 7;

	BFS(s);

	return 0;
}