#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> ar;
struct Pos
{
	int y;
	int x;
};
vector<Pos> centers;

void Input()
{
	string fi;

	cin >> fi;

	ar.resize(fi.size(), vector<char>(fi.size()));

	for (int i = 0; i < fi.size(); ++i)
	{
		ar[0][i] = fi[i];
	}

	for (int i = 1; i < ar.size(); ++i)
	{
		string input;
		cin >> input;

		for (int j = 0; j < input.size(); ++j)
		{
			ar[i][j] = input[j];
		}
	}
}

void ChooseCenter()
{
	if (ar.size() % 2 == 1)
		centers.push_back(
			Pos{ static_cast<int>(ar.size()) / 2,
			static_cast<int>(ar.size()) / 2 });
	else
	{
		int c = ar.size() / 2;
		centers.push_back(Pos{ c - 1, c - 1 });
		centers.push_back(Pos{ c - 1, c });
		centers.push_back(Pos{ c, c - 1 });
		centers.push_back(Pos{ c, c});
	}
}

void Rotate(Pos& center)
{
	int ci = center.y;
	int cj = center.x;

	for (int i = - 1; i <= 1; ++i)
	{
		for (int j = 1 + i; j <= 1; ++j)
		{
			int tmp = ar[ci + i][cj + j];
			ar[ci + i][cj + j] = ar[ci+ j][cj + i];
			ar[ci + j][cj + i] = tmp;
		}
	}

	for (int i = ci - 1; i <= ci + 1; ++i)
	{
		int f = cj - 1;
		int l = cj + 1;
		while (f < l)
		{
			int tmp = ar[i][f];
			ar[i][f] = ar[i][l];
			ar[i][l] = tmp;

			++f;
			--l;
		}
	}
}

void RollBack(Pos& center)
{

	int ci = center.y;
	int cj = center.x;

	for (int i = ci - 1; i <= ci + 1; ++i)
	{
		int f = cj - 1;
		int l = cj + 1;
		while (f < l)
		{
			int tmp = ar[i][f];
			ar[i][f] = ar[i][l];
			ar[i][l] = tmp;

			++f;
			--l;
		}
	}

	for (int i = -1; i <= 1; ++i)
	{
		for (int j = 1 + i; j <= 1; ++j)
		{
			int tmp = ar[ci + i][cj + j];
			ar[ci + i][cj + j] = ar[ci + j][cj + i];
			ar[ci + j][cj + i] = tmp;
		}
	}
}

bool CheckAAA()
{
	int aCnt = 0;
	for (int i = 0; i < ar.size(); ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (ar[i][j + k] == 'A')
					aCnt++;
				else
				{
					aCnt = 0;
					break;
				}
			}
		}

		if (aCnt == 3)
			return true;
	}

	return false;
}

bool isAAA = false;
void DFS(int curLev, int cIdx)
{
	if (cIdx != -1)
		Rotate(centers[cIdx]);

	isAAA = CheckAAA();
	if (isAAA)
		return;

	if (curLev == 6)
		return;

	for (int i = 0; i < centers.size(); ++i)
	{
		DFS(curLev + 1, i);

		RollBack(centers[i]);
	}
}

int main(void)
{
	Input();
	
	ChooseCenter();

	DFS(0, -1);

	cout << (isAAA ? "가능" : "불가능");

	return 0;
}