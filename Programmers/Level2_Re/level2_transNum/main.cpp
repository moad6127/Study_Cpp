#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;

int table[1000004];
vector<int> CHECK{2, 3};
int solution(int x, int y, int n) {
    int answer = 0;
    CHECK.push_back(n);
    memset(table, -1, sizeof(table));
    table[x] = 0;
    queue<int> q;
    q.push(x);
    while (q.size())
    {
        if (table[y] != -1)
        {
            break;
        }
        int now = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int next{};
            if (i == 2)
            {
                next = now + CHECK[i];
            }
            else
            {
                next = now * CHECK[i];
            }
            if (next > y)
            {
                continue;
            }
            if (table[next] != -1)
            {
                continue;
            }
            table[next] = table[now] + 1;
            q.push(next);
        }
    }
    return table[y];
}