#include <iostream>
#include <vector>

using namespace std;

vector<int> times('D' - 'A' + 1);
vector<int> tmp(times.size());

void MergeSort(int start, int end)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	MergeSort(start, mid);
	MergeSort(mid + 1, end);

	int a = start;
	int b = mid + 1;
	int t = 0;
	while (1)
	{
		if (a > mid && b > end)
			break;

		if (a > mid)
			tmp[t++] = times[b++];
		else if (b > end)
			tmp[t++] = times[a++];
		else if (times[a] <= times[b])
			tmp[t++] = times[a++];
		else
			tmp[t++] = times[b++];
	}

	for (int i = 0; i < t; ++i)
		times[start + i] = tmp[i];
}

int main(void)
{
	for (int i = 0; i < times.size(); ++i)
	{
		cin >> times[i];
	}

	MergeSort(0, times.size() - 1);

	int waitTime = 0;
	for (int i = 0; i < times.size() - 1; ++i)
	{
		waitTime += times[i] * (times.size() - i - 1);
	}

	cout << waitTime;

	return 0;
}