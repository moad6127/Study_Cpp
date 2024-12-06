#include <bits/stdc++.h>

using namespace std;

int t, n, m, cnt, a, b;
vector<int> adj[1004];
int visited[1004];

void dfs(int here)
{
	visited[here] = 1;
	for (int there : adj[here])
	{
		if (!visited[there])
		{
			dfs(there);
		}
	}
}
int main()
{
	cin >> t;
	for (int i = 0; i < t;i++)
	{
		for (int j = 0; j < 1004;j++)
		{
			adj[j].clear();
		}
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		cin >> n >> m;
		for (int j = 0;j < m;j++)
		{
			cin >> a >> b;
			adj[b].push_back(a);
			adj[a].push_back(b);
		}
		for (int j = 1; j <= n;j++)
		{
			if (!visited[j])
			{
				dfs(j);
				cnt++;
			}
		}
		if (m == n - 1 && cnt == 1)
		{
			cout << "tree" << '\n';
		}
		else
		{
			cout << "graph" << '\n';
		}
	}

}