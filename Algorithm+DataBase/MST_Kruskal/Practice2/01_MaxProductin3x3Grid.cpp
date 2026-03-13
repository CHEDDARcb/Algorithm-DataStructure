#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<int>> map(3, vector<int>(3));
vector<vector<bool>> visited(3, vector<bool>(3, false));
unordered_map<string, int> cnt;

int maxM;
void DFS(int curLev, int prevI, int prevJ, int mul)
{
	if (curLev == 3)
	{
		if (maxM < mul)
			maxM = mul;
		
		if (cnt.find(to_string(mul)) == cnt.end())
			cnt[to_string(mul)] = 1;
		else
			cnt[to_string(mul)]++;

		return;
	}

	if(prevJ != -1)
		visited[prevI][prevJ] = true;

	for (int i = prevI; i < map.size(); ++i)
	{
		int js;
		if (i == prevI)
			js = prevJ + 1;
		else
			js = 0;
		for (int j = js; j < map[i].size(); ++j)
		{
			if (visited[i][j]) continue;

			DFS(curLev + 1, i, j, mul * map[i][j]);
			visited[i][j] = false;
		}
	}
}

int main(void)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			cin >> map[i][j];
		}
	}

	DFS(0, 0, -1, 1);

	cout << cnt[to_string(maxM)];

	return 0;
}