#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

enum Direction
{
    NONE,
    A_LEFT,
    A_RIGHT,
    B_LEFT,
    B_RIGHT
};

struct Node
{
    int a_pos;
    int b_pos;
    int customer_idx;
    int count;
    Direction path[256];
};

struct DoorMove
{
    int da;
    int schedule;
};

int main()
{
    int seq[] = { 0, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 3 };
    int total_customers = 12;

    int doors[5];
    int start_a = -1, start_b = -1;
    for (int i = 0; i < 5; i++)
    {
        cin >> doors[i];
        if (doors[i] == 1)
        {
            if (start_a == -1)
            {
                start_a = i;
            }
            else
            {
                start_b = i;
            }
        }
    }

    bool visited[5][5][13] = { false };
    queue<Node> q;

    Node startNode = { start_a, start_b, 0, 0, {NONE} };
    q.push(startNode);
    visited[start_a][start_b][0] = true;

    const unordered_map<Direction, DoorMove> moveMap =
    {
        {A_LEFT,  {-1,  0}},
        {A_RIGHT, { 1,  0}},
        {B_LEFT,  { 0, -1}},
        {B_RIGHT, { 0,  1}}
    };

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        while (cur.customer_idx < total_customers &&
            cur.a_pos != seq[cur.customer_idx] &&
            cur.b_pos != seq[cur.customer_idx])
        {
            cur.customer_idx++;
        }

        if (cur.customer_idx == total_customers)
        {
            cout << cur.count << "\n";
            return 0;
        }

        for (const auto& [dir, move] : moveMap)
        {
            int next_a = cur.a_pos + move.da;
            int next_b = cur.b_pos + move.schedule;

            if (next_a < 0 || next_a >= 5 ||
                next_b < 0 || next_b >= 5 ||
                next_a == next_b)
            {
                continue;
            }

            if (!visited[next_a][next_b][cur.customer_idx])
            {
                visited[next_a][next_b][cur.customer_idx] = true;

                Node nextNode = cur;
                nextNode.a_pos = next_a;
                nextNode.b_pos = next_b;
                nextNode.path[nextNode.count] = dir;
                nextNode.count++;

                q.push(nextNode);
            }
        }
    }

    return 0;
}