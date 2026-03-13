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
vector<vector<int>> map(4, vector<int>(6));
vector<vector<bool>> pushed(4, vector<bool>(6, false));
int chikenCnt = 0;

struct Pos
{
	int y;
	int x;
};

void BFS(int y, int x)
{
	queue<Pos> que;
	que.push(Pos{ y, x });
	pushed[y][x] = 0;

	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		if (map[cur.y][cur.x] == 2)
			chikenCnt++;

		for (int i = 0; i < dir.size(); ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size() ||
				pushed[newY][newX] ||
				map[newY][newX] == 1)
				continue;

			que.push(Pos{ newY, newX });
			pushed[newY][newX] = true;
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

	cout << chikenCnt;

	return 0;
}
