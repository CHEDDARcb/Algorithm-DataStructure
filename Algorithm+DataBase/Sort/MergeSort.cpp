#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = { 5, 3, 8, 1, 2, 7 };
vector<int> tmp(arr.size());

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
			tmp[t++] = arr[b++];
		else if (b > end)
			tmp[t++] = arr[a++];
		else if (arr[a] <= arr[b])
			tmp[t++] = arr[a++];
		else if (arr[a] > arr[b])
			tmp[t++] = arr[b++];
	}

	for (int i = 0; i < t; ++i)
		arr[start + i] = tmp[i];
}

int main(void)
{
	MergeSort(0, arr.size() - 1);

	for (const auto& data : arr)
		cout << data << " ";

	return 0;
}