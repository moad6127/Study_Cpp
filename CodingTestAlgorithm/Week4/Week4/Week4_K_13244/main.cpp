#include <bits/stdc++.h>

using namespace std;

int T, N, M, A, B;
vector<int> a[1004];
int visited[1004];
void dfs(int node)
{
	visited[node] = 1;
	for (auto nextNode : a[node])
	{
		if (!visited[nextNode])
		{
			dfs(nextNode);
		}
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		bool check{};
		int count{};
		cin >> N >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> A >> B;
			a[A].push_back(B);
			a[B].push_back(A);
		}
		for (int j = 1; j <= N; j++)
		{
			if (!visited[j])
			{
				count++;
				dfs(j);
			}
		}

		if ((count == 1) && (N - 1 == M))
		{
			cout << "tree" << '\n';
		}
		else
		{
			cout << "graph" << '\n';
		}
	}
}