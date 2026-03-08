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
const vector<vector<int>> map =
{
	{0, 0, 0, 0, -1},
	{-1, 0, -1, 0, 0},
	{0, 0, 0, 0, -1}
};
vector<vector<bool>> visited(3, vector<bool>(5, false));
const int cy = 2;
const int cx = 0;
const int fy = 0;
const int fx = 3;

int cMinCost = INT_MAX;
int fMinCost = INT_MAX;

void FindTarget(int y, int x, int ty, int tx, int cost)
{
	visited[y][x] = true;

	if (y == ty && x == tx)
	{
		if(ty == cy && tx == cx)
		{
			if (cMinCost > cost)
				cMinCost = cost;
		}
		else if (ty == fy && tx == fx)
		{
			if (fMinCost > cost)
				fMinCost = cost;
		}

		return;
	}

	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			visited[newY][newX] ||
			map[newY][newX] == -1)
			continue;

		FindTarget(newY, newX, ty, tx, cost + 1);
		visited[newY][newX] = false;
	}
}

void FindFriend(int y, int x, int cost)
{
	visited[y][x] = true;

	if (y == fy && x == fx)
	{
		if (fMinCost > cost)
			fMinCost = cost;

		return;
	}

	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			visited[newY][newX] ||
			map[newY][newX] == -1)
			continue;

		FindFriend(newY, newX, cost + 1);
		visited[newY][newX] = false;
	}
}

int main(void)
{
	FindTarget(0, 0, cy, cx, 0);
	
	visited.assign(3, vector<bool>(5, false));

	FindTarget(cy, cx, fy, fx, 0);


	//FindFriend(cy, cx, 0);

	int result = cMinCost + fMinCost;

	cout << result;

	return 0;
}