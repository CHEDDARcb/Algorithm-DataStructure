#include <iostream>
#include <vector>

using namespace std;

const string str1 = "ABABCGKABABC";
const string str2 = "BTBCKABABCT";
vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

int maxLength = 0;
int endPosition = 0;

int main()
{
	for (int i = 1; i <= str1.size(); ++i)
	{
		for (int j = 1; j <= str2.size(); ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > maxLength)
				{
					maxLength = dp[i][j];
					endPosition = i;
				}
			}
			else
				dp[i][j] = 0;
		}
	}

	string ret = str1.substr(endPosition - maxLength, maxLength);

	cout << ret;
}