#include <iostream>
#include <vector>

using namespace std;

//1 0 0
//1 2 2
//0 3 0
//3 -10 -5
//15 -10 50
//15 -10 10
//0 6 4
const int dir[3][2] =
{
	{-1, -1},
	{-1, 0},
	{-1, 1}
};
vector<vector<int>> board(7, vector<int>(3));
vector<vector<int>> dp(7, vector<int>(3, 0));
vector<vector<bool>> reachable(7, vector<bool>(3, true));
int ignoreNum;
void Init()
{
	ignoreNum = board[0][0];
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			int n;
			cin >> n;

			if (ignoreNum > n)
				ignoreNum = n;

			board[i][j] = n;
			if (n == 0)
				reachable[i][j] = false;
		}
	}
	ignoreNum--;

	for (int j = 0; j < dp[0].size(); ++j)
	{
		if (board[0][j] != 0)
			dp[0][j] = board[0][j];
	}
}

void MakeDPTable()
{
	for (int i = 1; i < dp.size(); ++i)
	{
		for(int j = 0; j < dp[i].size(); ++j)
		{
			if (!reachable[i][j])
			{
				dp[i][j] = ignoreNum;
				continue;
			}

			int mx = ignoreNum;
			for (int k = 0; k < 3; ++k)
			{
				int newI = i + dir[k][0];
				int newJ = j + dir[k][1];

				if (newI < 0 || newI >= board.size() ||
					newJ < 0 || newJ >= board[newI].size())
					continue;

				if (!reachable[newI][newJ])
					continue;

				int tmp = dp[newI][newJ] + board[i][j];
				if (mx < tmp)
					mx = tmp;
			}
			if (mx == ignoreNum)
				reachable[i][j] = false;

			dp[i][j] = mx;
		}
	}
}

int main(void)
{
	Init();

	MakeDPTable();

	int mx = ignoreNum;
	for (int j = 0; j < dp[dp.size() - 1].size(); ++j)
	{
		if (mx < dp[dp.size() - 1][j])
			mx = dp[dp.size() - 1][j];
	}

	cout << mx;

	return 0;
}