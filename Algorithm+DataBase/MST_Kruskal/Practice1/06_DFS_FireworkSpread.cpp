#include <iostream>
#include <vector>

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
vector<vector<int>> map(4, vector<int>(5, 999));
vector<vector<bool>> visited(4, vector<bool>(5, false));
struct Pos
{
	int y;
	int x;
};
vector<Pos> firePoses;

void DFS(int y, int x, int sc)
{
	visited[y][x] = true;

	if (map[y][x] < sc)
		return;

	map[y][x] = sc;

	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			visited[newY][newX])
			continue;

		DFS(newY, newX, sc + 1);

		visited[newY][newX] = false;
	}
}

int main(void)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			int n;
			cin >> n;

			if (n == 1)
				firePoses.push_back(Pos{ i, j });
		}
	}

	for (int i = 0; i < firePoses.size(); ++i)
	{
		DFS(firePoses[i].y, firePoses[i].x, 0);
	}

	int mxsc = INT_MIN;
	for (auto& row : map)
	{
		for (auto& data : row)
		{
			if (mxsc < data)
				mxsc = data;
		}
	}

	cout << mxsc;

	return 0;
}