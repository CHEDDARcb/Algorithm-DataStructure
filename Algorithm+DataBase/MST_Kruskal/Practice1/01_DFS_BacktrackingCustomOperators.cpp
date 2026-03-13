#include <iostream>
#include <vector>

using namespace std;

vector<int> nums(3);
vector<string> oper = { "!!", "#", "$", "&", "^" };
const int mn = 20;
int cnt = 0;

int Calculate(int prev, int cur, string op)
{
	if (op == "!!") return prev + (cur * 2);
	if (op == "#")  return prev - (cur * 2);
	if (op == "$")  return prev + 10;
	if (op == "&")  return prev + (cur * cur);
	if (op == "^")  return 0;
	return cur;
}

void DFS(int prevN, int lev)
{
	if (lev == 3)
	{
		if (prevN >= 20)
			cnt++;
		return;
	}

	int curN = nums[lev];
	int nxtN;

	for (int i = 0; i < oper.size(); ++i)
	{
		nxtN = Calculate(prevN, curN, oper[i]);
		DFS(nxtN, lev + 1);
	}
}

int main(void)
{
	for (int i = 0; i < 3; ++i)
		cin >> nums[i];


	DFS(nums[0], 1);

	cout << cnt;

	return 0;
}