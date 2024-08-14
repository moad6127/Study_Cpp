#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> dist(N + 1, 987654321);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

    for (auto r : road)
    {
        adj[r[0]].push_back({ r[2],r[1] });
        adj[r[1]].push_back({ r[2],r[0] });
    }
    pq.push({ 0,1 });
    dist[1] = 0;
    while (pq.size())
    {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();
        for (auto there : adj[here])
        {
            int _dist = there.first;
            int _there = there.second;
            if (dist[_there] > dist[here] + _dist)
            {
                dist[_there] = dist[here] + _dist;
                pq.push({ dist[_there],_there });
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
        {
            answer++;
        }
    }
    return answer;
}