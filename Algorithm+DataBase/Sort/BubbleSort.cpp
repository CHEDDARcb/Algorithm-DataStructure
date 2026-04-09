#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = { 8, 7, 3, 9, 5, 4 };

void BubbleSort()
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main(void)
{
	BubbleSort();

	for (const auto& data : arr)
		cout << data << " ";

	return 0;
}