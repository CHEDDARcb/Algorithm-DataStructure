#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};
vector<vector<int>> map(3, vector<int>(3, 999));

void DFS(int y, int x, int str)
{
	if (map[y][x] <= str)
		return;

	map[y][x] = str;
	
	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			map[newY][newX] < str + 1)
			continue;

		DFS(newY, newX, str + 1);
	}
}

int main(void)
{
	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;

	DFS(y1, x1, 1);
	DFS(y2, x2, 1);

	for (auto& row : map)
	{
		for (auto& data : row)
			cout << data;
		cout << endl;
	}
}