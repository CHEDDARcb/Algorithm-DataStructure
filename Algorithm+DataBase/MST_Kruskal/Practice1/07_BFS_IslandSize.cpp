#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};
vector<vector<int>> map(4, vector<int>(4));
struct Pos
{
	int y;
	int x;
	int size;
	vector<pair<int, int>> path;

	bool IsVisited(int _y, int _x)
	{
		for (int i = 0; i < path.size(); ++i)
		{
			if (path[i].first == _y &&
				path[i].second == _x)
				return true;
		}
		return false;
	}
};
int maxSize = INT_MIN;
void BFS(int y, int x)
{
	queue<Pos> que;
	que.push(Pos{y, x, 0});
	que.front().path.push_back(make_pair(y, x));

	if (map[y][x] == 1)
		que.front().size = 1;

	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		if (maxSize < cur.size)
			maxSize = cur.size;

		for (int i = 0; i < dir.size(); ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size() ||
				cur.IsVisited(newY, newX))
				continue;

			Pos nxt{ newY, newX, 0 };
			if (map[newY][newX])
				nxt.size = cur.size + 1;
			nxt.path = cur.path;
			nxt.path.push_back(make_pair(newY, newX));
			que.push(nxt);
		}
	}
}

int main(void)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
			cin >> map[i][j];
	}

	BFS(0, 0);

	cout << maxSize;

	return 0;
}