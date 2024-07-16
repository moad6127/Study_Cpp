#include <bits/stdc++.h>

using namespace std;

int n, m, st, ed, u, v, p;
int adj[504][504];
int dist[504];
void dij()
{
	fill(dist, dist + 504, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,st });
	dist[st] = 0;
	while (pq.size())
	{
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist)
		{
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			if (adj[here][i] == -1)
			{
				continue;
			}
			int _dist = adj[here][i];
			if (dist[i] > dist[here] + _dist)
			{
				dist[i] = dist[here] + _dist;
				pq.push({ dist[i],i });
			}
		}
	}
}
void era()
{
	queue<int>q;
	q.push(ed);
	while (q.size())
	{
		int cx = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (dist[cx] == dist[i] + adj[i][cx] && adj[i][cx] != -1)
			{
				adj[i][cx] = -1;
				q.push(i);
			}
		}
	}
}
int main()
{
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}
		memset(adj, -1, sizeof(adj));
		cin >> st >> ed;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> p;
			adj[u][v] = p;
		}
		dij();
		era();
		dij();
		if (dist[ed] == 987654321)
		{
			cout << -1<<'\n';
		}
		else
		{
			cout << dist[ed]<<'\n';
		}
	}
}