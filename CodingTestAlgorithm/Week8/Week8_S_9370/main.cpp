#include <bits/stdc++.h>

using namespace std;
int T;
int n, m, t, s, g, h;
int a, b, c,li;
int dist[2004];
int main()
{
	cin >> T;
	while (T--)
	{
		vector<pair<int, int>> adj[2004];
		vector<int> list;
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			c *= 2;
			if (a == g && b == h)
			{
				c--;
			}
			else if (a == h && b == g)
			{
				c--;
			}
			adj[a].push_back({ c,b });
			adj[b].push_back({ c,a });
		}
		for (int i = 0; i < t; i++)
		{
			cin >> li;
			list.push_back(li);
		}
		sort(list.begin(), list.end());
		fill(dist, dist + 2004, 987654322);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0,s});
		dist[s] = 0;
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
		for (auto e : list)
		{
			if (dist[e] % 2 == 1)
			{
				cout << e << '\n';
			}
		}
	}
}