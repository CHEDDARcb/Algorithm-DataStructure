#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int ROW = 7;
const int COL = 3;
const int dy[3] = { -1, -1, -1 };
const int dx[3] = { -1, 0, 1 };

int main()
{
    vector<vector<int>> board(ROW, vector<int>(COL));
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            cin >> board[i][j];
        }
    }

    const int NEG_INF = INT_MIN / 2;
    vector<vector<int>> dp(ROW, vector<int>(COL, NEG_INF));

    // 시작점
    if (board[0][0] != 0)
        dp[0][0] = board[0][0];

    for (int i = 1; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (board[i][j] == 0)
                continue; // 벽

            for (int k = 0; k < 3; ++k)
            {
                int py = i + dy[k];
                int px = j + dx[k];

                if (py < 0 || py >= ROW || px < 0 || px >= COL)
                    continue;

                if (dp[py][px] == NEG_INF)
                    continue; // 이전 칸에 도달 불가

                dp[i][j] = max(dp[i][j], dp[py][px] + board[i][j]);
            }
        }
    }

    int answer = NEG_INF;
    for (int j = 0; j < COL; ++j)
    {
        answer = max(answer, dp[ROW - 1][j]);
    }

    if (answer == NEG_INF)
        cout << 0;
    else
        cout << answer;

    return 0;
}