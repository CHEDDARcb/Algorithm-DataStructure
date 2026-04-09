#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = { 8, 7, 3, 9, 5, 4 };

void InsertionSort()
{
	for (int i = 1; i < arr.size(); ++i)
	{
		int key = arr[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (arr[j] > key)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = key;
	}
}

int main(void)
{
	InsertionSort();

	for (const auto& data : arr)
		cout << data << " ";

	return 0;
}