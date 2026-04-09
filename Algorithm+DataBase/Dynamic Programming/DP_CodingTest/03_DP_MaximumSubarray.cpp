#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    //vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
     vector<int> nums = {5, -100, 3  };

    int prevSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        if (prevSum + nums[i] < nums[i])
        {
            prevSum = nums[i];
        }
        else
        {
            prevSum += nums[i];
        }

        if (maxSum < prevSum)
        {
            maxSum = prevSum;
        }
    }

    cout << maxSum << endl;

    return 0;
}