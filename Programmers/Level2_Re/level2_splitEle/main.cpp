#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<vector<int>> tree, int n)
{
    int result{1};
    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (auto next : tree[now])
        {
            if (visited[next])
            {
                continue;
            }
            q.push(next);
            visited[now] = 1;
            result++;
        }
    }
    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n + 1;


    for (int i = 0; i < wires.size(); i++)
    {
        vector<vector<int>> tree(n + 1);
        for (int j = 0; j < wires.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            tree[wires[j][0]].push_back(wires[j][1]);
            tree[wires[j][1]].push_back(wires[j][0]);
        }
        int cnt = bfs(tree, n);
        answer = min(answer, abs(cnt - (n - cnt)));

    }


    return answer;
}
int main()
{
    solution(9, { {1, 3},{2, 3},{3, 4},{4, 5},{4, 6},{4, 7},{7, 8},{7, 9} });
}