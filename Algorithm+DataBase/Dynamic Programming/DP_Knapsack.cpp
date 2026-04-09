#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int capacity = 5;

	vector<string> items = { "마법반지", "신검", "용방패", "왕의 왕관" };
	vector<int> weights = { 2, 3, 4, 5 };
	vector<int> values = { 3, 4, 5, 6 };
	int n = items.size();

	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

	cout << "RPG게임 - 던전 아이템 수집하기" << endl;
	cout << "인벤토리 용량: " << capacity << "칸\n" << endl;

	cout << "발견한 아이템들" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << " " << (i + 1) << ". " << items[i]
			<< "(용량: " << weights[i] << "칸, 가치: " << values[i] << ")" << endl;
	}
	cout << endl;

	for (int i = 1; i <= n; ++i)
	{
		cout << i << "단계: " << items[i - 1] << "검토중.." << endl;

		for (int w = 0; w <= capacity; ++w)
		{
			if (weights[i - 1] > w)
			{
				dp[i][w] = dp[i - 1][w];
			}
			else
			{
				int not_take = dp[i - 1][w];
				int take = dp[i - 1][w - weights[i - 1]] + values[i - 1];
				dp[i][w] = max(not_take, take);

				if (w == capacity)
				{
					cout << " 용량 " << w << "칸 : max(" << not_take
						<< ", " << take << ")=" << dp[i][w] << endl;
				}
			}
		}
		cout << endl;
	}

	cout << "최종 DP 테이블: " << endl;
	cout << "       ";
	for (int w = 0; w <= capacity; ++w)
	{
		cout << "c" << w << " ";
	}
	cout << endl;

	for (int i = 0; i <= n; ++i)
	{
		if (i == 0)
			cout << "없음:  ";
		else
		{
			cout << i << "개:  ";
		}

		for (int w = 0; w <= capacity; ++w)
		{
			cout << dp[i][w] << " ";
		}
		cout << endl;
	}

	cout << "\n  최대가치: " << dp[n][capacity] << endl;

	cout << "\n  선택된 아이템들: " << endl;
	vector<bool> selected(n, false);
	int w = capacity;

	for (int i = n; i > 0 && w > 0; --i)
	{
		if (dp[i][w] != dp[i - 1][w])
		{
			selected[i - 1] = true;
			cout << " V" << items[i - 1]
				<< " (용량: " << weights[i - 1] << "칸, 가치: " << values[i - 1] << ")" << endl;
			w -= weights[i - 1];
		}
		else
			cout << " X" << items[i - 1] << " (선택하지 않음" << endl;
	}

	int total_weight = 0, total_value = 0;
	for (int i = 0; i < n; ++i)
	{
		if (selected[i])
		{
			total_weight += weights[i];
			total_value += values[i];
		}
	}

	cout << "\n 최종 요약: " << endl;
	cout << " 총 사용 용량: " << total_weight << "/" << capacity << "칸" << endl;
	cout << " 총 가치: " << total_value << endl;
	cout << " 남은 용량: " << (capacity - total_weight) << "칸" << endl;
}