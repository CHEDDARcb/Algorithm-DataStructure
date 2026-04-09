#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = { 5, 3, 8, 1, 2, 7 };

void SelectionSort()
{
	for (int i = 0; i < arr.size() - 1; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < arr.size(); ++j)
		{
			if (arr[minIdx] > arr[j])
				minIdx = j;
		}

		int tmp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = tmp;
	}
}

int main(void)
{
	SelectionSort();

	for (const auto& data : arr)
		cout << data << " ";

	return 0;
}