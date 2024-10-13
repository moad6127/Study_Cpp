#include <bits/stdc++.h>

using namespace std;
int n, m, A, B, MAX;

vector<int> adj[10001];
int visited[10001];
int dp[10001];
int dfs(int node)
{
	int result{1};
	visited[node] = 1;
	for (auto e : adj[node])
	{
		if (visited[e])
		{
			continue;
		}
		result += dfs(e);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> A >> B;
		adj[B].push_back(A);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i);
		MAX = max(MAX, dp[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (MAX == dp[i])
		{
			cout << i << ' ';
		}
	}
}