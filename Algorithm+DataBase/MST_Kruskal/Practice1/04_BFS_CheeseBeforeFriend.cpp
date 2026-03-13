#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};
const vector<vector<int>> map =
{
	{0, 0, 0, 0, -1},
	{-1, 0, -1, 0, 0},
	{0, 0, 0, 0, -1}
};
int cy;
int cx;
int fy;
int fx;

struct Pos
{
	int y;
	int x;
	int cost;
};

int BFS(int sy, int sx, int ty, int tx)
{
	vector<vector<bool>> pushed(3, vector<bool>(5, false));
	int cy;
	queue<Pos> que;
	que.push(Pos{ sy, sx, 0 });
	pushed[sy][sx] = true;

	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		if (cur.y == ty && cur.x == tx)
			return cur.cost;

		for (int i = 0; i < dir.size(); ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size() ||
				map[newY][newX] == -1 ||
				pushed[newY][newX])
				continue;

			que.push(Pos{ newY, newX, cur.cost + 1 });
			pushed[newY][newX] = true;
		}
	}
}

int main(void)
{
	cin >> cy >> cx >> fy >> fx;

	int cheeseCost = BFS(0, 0, cy, cx);
	int freindCost = BFS(cy, cx, fy, fx);

	int result = cheeseCost + freindCost;
	cout << result;

	return 0;
}