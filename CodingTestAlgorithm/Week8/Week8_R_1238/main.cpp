#include <bits/stdc++.h>

using namespace std;

int n, m, x;
int result{ -1 };
int a, b, c;
vector<pair<int,int>> adj[1004], adjRe[1004];
int dist[1004], dist2[1004];

void dij(int* dist, vector<pair<int, int>>* adj)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,x });
	dist[x] = 0;
	while (pq.size())
	{
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist)
		{
			continue;
		}
		for (pair<int, int> there : adj[here]) {
			int _dist = there.first;
			int _there = there.second;
			if (dist[_there] > dist[here] + _dist) {
				dist[_there] = dist[here] + _dist;
				pq.push(make_pair(dist[_there], _there));
			}
		}
	}
}


int main()
{
	fill(dist, dist + 1004, 987654321);
	fill(dist2, dist2 + 1004, 987654321);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adjRe[b].push_back({ c,a });
	}
	dij(dist, adj);
	dij(dist2, adjRe);
	for (int i = 1; i <= n; i++)
	{
		if (i == x)
		{
			continue;
		}
		result = max(result, dist[i] + dist2[i]);
	}
	cout << result;
}