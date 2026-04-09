#include <iostream>
#include <vector>

using namespace std;

const int ROW = 4;
const int COL = 4;
vector<vector<int>> board(ROW, vector<int>(COL));
vector<vector<bool>> visisted(ROW, vector<bool>(COL, false));
int minDamge = INT_MAX;
const int sy = 0;
const int sx = 0;
const int gy = 3;
const int gx = 3;
const int dir[4][2] =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};
struct Pos
{
	int y;
	int x;
};

vector<Pos> result;

void DFS(int y, int x, int damage, vector<Pos> path)
{
	if (y == gy && gx == x)
	{
		if (damage < minDamge)
		{
			minDamge = damage;
			result = path;
		}

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= ROW ||
			newX < 0 || newX >= COL)
			continue;

		if (visisted[newY][newX])
			continue;

		if (damage + board[newY][newX] >= minDamge)
			continue;

		path.push_back(Pos{ newY, newX });
		visisted[newY][newX] = true;

		DFS(newY, newX, damage + board[newY][newX], path);

		visisted[newY][newX] = false;
		path.pop_back();
	}
}

int main(void)
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			cin >> board[i][j];
		}
	}

	visisted[sy][sx] = true;
	DFS(sy, sx, 0, vector<Pos>{Pos{ sy, sx }});

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i].y << "," << result[i].x << endl;
	}

	return 0;
}