#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> dis(N + 1, 1000000);
    vector<vector<pair<int, int>>> graph(N+1);
    for (int i = 0; i < road.size(); i++)
    {
        int a{road[i][0]}, b{road[i][1]}, c{road[i][2]};
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ 0,1 });
    dis[1] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dis[now] < dist)
        {
            continue;
        }
        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = dist + graph[now][i].second;

            if (cost < dis[graph[now][i].first])
            {
                dis[graph[now][i].first] = cost;
                pq.push({ -cost,graph[now][i].first });
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (dis[i] <= K)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int> > road{ {1, 2, 1},{1, 2, 100},{5, 2, 2},{1, 4, 2},{5, 3, 1},{5, 4, 2} };
    solution(5, road, 3);
}