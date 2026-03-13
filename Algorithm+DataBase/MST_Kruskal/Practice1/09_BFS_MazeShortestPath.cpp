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
	{0, 0, 0, 0 },
	{1, 1, 0, 1 },
	{0, 0, 0, 0 },
	{0, 1, 1, 0 },
};
vector<vector<bool>> pushed(4, vector<bool>(4));
int sy, sx;
int ey, ex;

struct Pos
{
	int y;
	int x;
	int cost;
};

int BFS()
{
	queue<Pos> que;
	que.push(Pos{sy, sx, 0});
	pushed[sy][sx] = true;

	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		if (cur.y == ey && cur.x == ex)
			return cur.cost;

		for (int i = 0; i < dir.size(); ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size() ||
				pushed[newY][newX] ||
				map[newY][newX] == 1)
				continue;

			que.push(Pos{ newY, newX, cur.cost + 1 });
			pushed[newY][newX] = true;
		}
	}

	return 0;
}

int main(void)
{
	cin >> sy >> sx >> ey >> ex;

	int result = BFS();

	cout << result;

	return 0;
}