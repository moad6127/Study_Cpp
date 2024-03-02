#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> graph(n + 1);
    for (auto e : roads)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    vector<int> visit(n + 1, -1);
    queue<int> q;
    q.push(destination);
    visit[destination] = 0;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (auto next : graph[now])
        {
            if (visit[next] == -1 || visit[now] + 1 < visit[next])
            {
                visit[next] = visit[now] + 1;
                q.push(next);
            }
        }
    }
    for (auto e : sources)
    {
        answer.push_back(visit[e]);
    }
    return answer;
}

int main()
{
    vector<vector<int>> roads {{1, 2}, { 1, 4 }, { 2, 4 }, { 2, 5 }, { 4, 5 }};
    vector<int> so{1, 3,5};
    solution(5, roads, so, 5);
}