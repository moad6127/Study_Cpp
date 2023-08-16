#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[10004];
int hackCount[10004];
int maxCount;
int dfs(int node)
{
	int result{1};

	for (auto there : adj[node])
	{
		result += dfs(there);
	}

	return result;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A{}, B{};
		cin >> A >> B;
		adj[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		hackCount[i] = dfs(i);
	}
	maxCount = *max_element(hackCount, hackCount + N + 1);
	for (int i = 1; i <= N; i++)
	{
		if (hackCount[i] == maxCount)
		{
			cout << i << " ";
		}
	}


	return 0;
}