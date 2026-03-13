#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> ar =
{
	{'a', 'b', 'c'},
	{'a', 'b', 'c'},
	{'a', 'b', 'c'},
};

void Rotate(int ci, int cj)
{
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = 1 + i; j <= 1; ++j)
		{
			int tmp = ar[ci + i][cj + j];
			ar[ci + i][cj + j] = ar[ci + j][cj + i];
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

int main(void)
{
	Rotate(1, 1);

	return 0;
}