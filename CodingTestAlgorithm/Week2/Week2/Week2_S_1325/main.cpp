#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[10004];
int visited[10004];
int hackCount[10004];
int maxCount;
int dfs(int node)
{
	int result{1};
	visited[node] = 1;
	for (auto there : adj[node])
	{
		if (visited[there])
		{
			continue;
		}
		result += dfs(there);
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A{}, B{};
		cin >> A >> B;
		adj[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));
		hackCount[i] = dfs(i);
		maxCount = max(maxCount, hackCount[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		if (hackCount[i] == maxCount)
		{
			cout << i << " ";
		}
	}

}