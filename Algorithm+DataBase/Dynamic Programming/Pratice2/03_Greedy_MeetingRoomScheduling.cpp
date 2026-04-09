#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int start;
	int end;
};
vector<Node> schedule;

void MergeSort(int start, int end, vector<Node>& tmp)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	MergeSort(start, mid, tmp);
	MergeSort(mid + 1, end, tmp);

	int a = start;
	int b = mid + 1;
	int t = 0;
	while (1)
	{
		if (a > mid && b > end)
			break;

		if (a > mid)
			tmp[t++] = schedule[b++];
		else if (b > end)
			tmp[t++] = schedule[a++];
		else if (schedule[a].end <= schedule[b].end)
			tmp[t++] = schedule[a++];
		else
			tmp[t++] = schedule[b++];
	}

	for (int i = 0; i < t; ++i)
	{
		schedule[start + i] = tmp[i];
	}
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int s, e;
		cin >> s >> e;

		schedule.push_back({ s, e });
	}

	vector<Node> tmp(n);
	MergeSort(0, n - 1, tmp);

	int s = 0;
	int meetingCnt = 0;
	for (int i = 0; i < schedule.size(); ++i)
	{
		if (s <= schedule[i].start)
		{
			++meetingCnt;
			s = schedule[i].end;
		}
	}

	cout << meetingCnt;

	return 0;
}