#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{1, 0},
	{1, -1},
	{1, 1},
	{0, -1},
	{0, 1},
};
vector<vector<int>> map(4, vector<int>(5));
vector<vector<bool>> pushed(4, vector<bool>(5, false));
struct Pos
{
	int y;
	int x;
	int sc;
};
queue<Pos> que;

void Input()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == 1)
			{
				que.push(Pos{ i, j, 0 });
				pushed[i][j] = true;
			}
		}
	}
}

int maxSc = -1;
void BFS()
{
	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		if (maxSc < cur.sc)
			maxSc = cur.sc;

		for (int i = 0; i < dir.size(); ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size() ||
				pushed[newY][newX])
				continue;

			que.push(Pos{ newY, newX, cur.sc + 1 });
			pushed[newY][newX] = true;
		}
	}
}

int main(void)
{
	Input();

	BFS();

	cout << maxSc;

	return 0;
}