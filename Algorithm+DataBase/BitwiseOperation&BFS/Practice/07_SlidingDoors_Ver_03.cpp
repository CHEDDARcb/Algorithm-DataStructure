#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int custumerNum = 12;
const int maxDoorNum = 5;
const int custumer[custumerNum] = { 0, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 3 };
bool visited[maxDoorNum][maxDoorNum][custumerNum] = { false };
struct Node
{
	int ai;
	int bi;
	int cost;
	int ci;
};
struct DoorMove
{
	int da;
	int schedule;
};
const vector<DoorMove> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};
int BFS(int ai, int bi)
{
	queue<Node> que;
	que.push({ ai, bi, 0, 0 });
	visited[ai][bi][0] = true;

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		int ci;
		for (ci = cur.ci; ci < custumerNum; ++ci)
		{
			if (cur.ai == custumer[ci] ||
				cur.bi == custumer[ci])
				break;
		}

		if (ci == custumerNum)
			return cur.cost;

		for (int i = 0; i < dir.size(); ++i)
		{
			int newAI = cur.ai + dir[i].da;
			int newBI = cur.bi + dir[i].schedule;

			if (newAI < 0 || newAI >= maxDoorNum ||
				newBI < 0 || newBI >= maxDoorNum ||
				newAI == newBI)
				continue;

			if (visited[newAI][newBI][ci])
				continue;

			visited[newAI][newBI][ci] = true;
			que.push({ newAI, newBI, cur.cost + 1, ci });
		}
	}
}

int main(void)
{
	int ai, bi;
	bool bTurn = false;
	for (int k = 0; k < maxDoorNum; ++k)
	{
		int n;
		cin >> n;

		if (n == 1 && !bTurn)
		{
			ai = k;
			bTurn = true;
		}
		else if (n == 1 && bTurn)
			bi = k;
	}

	int result = BFS(ai, bi);

	cout << result;

	return 0;
}