#include <bits/stdc++.h>

using namespace std;

int N,M;
int a[14];
vector<int> adj[14];

int result = 100000000;
int visited[14];
int comp[14];

pair<int, int> dfs(int h, int value)
{
	visited[h] = 1;
	pair<int, int> ret = { 1,a[h] };
	for (int e : adj[h])
	{
		if (comp[e] != value)
		{
			continue;
		}
		if (visited[e])
		{
			continue;
		}
		pair<int, int> temp = dfs(e, value);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			int input{};
			cin >> input;
			adj[i].push_back(input);
			adj[input].push_back(i);
		}
	}
	for (int i = 1; i < (1 << N) - 1; i++)
	{
		memset(comp, 0, sizeof(comp));
		memset(visited, 0, sizeof(visited));
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else
			{
				idx2 = j + 1;
			}
		}
		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);
		if (comp1.first + comp2.first == N)
		{
			result = min(result, abs(comp1.second - comp2.second));
		}
	}
	if (result == 100000000)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
}