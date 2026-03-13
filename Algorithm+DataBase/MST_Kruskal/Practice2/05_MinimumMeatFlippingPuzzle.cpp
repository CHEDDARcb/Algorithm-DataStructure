#include <iostream>

using namespace std;

string meets;

void Reverse(string& cpyMeets, int idx)
{
	for (int i = idx - 1; i <= idx + 1; ++i)
	{
		if (i < 0 || i >= static_cast<int>(cpyMeets.size())) continue;

		cpyMeets[i] = (cpyMeets[i] == 'O' ? 'X' : 'O');
	}
}

int CountReverse(string cpyMeets, char target)
{
	int cnt = 0;
	for (int i = 0; i <= cpyMeets.size() - 2; ++i)
	{
		if (cpyMeets[i] != target)
		{
			Reverse(cpyMeets, i + 1);
			++cnt;
		}
	}

	if (cpyMeets[cpyMeets.size() - 1] == target && cnt <= 4)
		return cnt;
	else
		return INT_MAX - 1;
}

int main(void)
{
	cin >> meets;

	string oCase = meets;
	int oCnt1 = CountReverse(oCase, 'O');
	Reverse(oCase, 0);
	int oCnt2 = CountReverse(oCase, 'O') + 1;
	int minOCnt = min(oCnt1, oCnt2);

	string xCase = meets;
	int xCnt1 = CountReverse(xCase, 'X');
	Reverse(xCase, 0);
	int xCnt2 = CountReverse(xCase, 'X') + 1;
	int minXCnt = min(xCnt1, xCnt2);

	int minCnt = min(minOCnt, minXCnt);
	if (minCnt <= 4)
		cout << minCnt;
	else
		cout << "impossible";

	return 0;
}