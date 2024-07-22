#include <bits/stdc++.h>

using namespace std;

int n, m, st, ed;
vector<pair<int, int>> adj[53];
int city[53];
long long dist[53];
queue<int> q;
int flag, visited[53];
int main()
{
	cin >> n >> st >> ed >> m;
	for (int i = 0; i < m; i++)
	{
		int s{};
		int e{};
		int d{};
		cin >> s >> e >> d;
		adj[s].push_back({ e,d });
	}
	for (int i = 0; i < n; i++)
	{
		cin >> city[i];
	}
	fill(dist, dist + n, -1e18);
	dist[st] = city[st];
	//벨만 포트 알고리즘
	for (int i = 0; i < n; i++)
	{
		for (int here = 0; here < n; here++)
		{
			for (auto there : adj[here])
			{
				int _dist = there.second;
				int _there = there.first;
				if (dist[here] != -1e18 && dist[here] + city[_there] - _dist > dist[_there])
				{
					dist[_there] = dist[here] + city[_there] - _dist;
					if (i == n - 1)
					{
						q.push(here);
					}
				}
			}
		}
	}
	//싸이클 확인
	while (q.size())
	{
		int here = q.front();
		q.pop();
		for (auto there : adj[here])
		{
			if (there.first == ed)
			{
				flag = 1;
				break;
			}
			if (!visited[there.first])
			{
				visited[there.first] = 1;
				q.push(there.first);
			}
		}
		if (flag)
		{
			break;
		}
	}
	if (dist[ed] == -1e18)
	{
		cout << "gg";
	}
	else if (flag)
	{
		cout << "Gee";
	}
	else
	{
		cout << dist[ed];
	}
}