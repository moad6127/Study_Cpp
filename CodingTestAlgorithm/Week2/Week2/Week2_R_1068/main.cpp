#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[51];
int ignNode;
int result;
void dfs(int node)
{
	int prevResult{ result };
	if (node == ignNode)
	{
		return;
	}
	if (adj[node].size() == 0)
	{
		result++;
		return;
	}

	for (int i = 0; i < adj[node].size(); i++)
	{
		dfs(adj[node][i]);
	}
	if (prevResult == result)
	{
		result++;
	}
}
int main()
{
	cin >> N;
	int root{};
	for (int i = 0; i < N; i++)
	{
		int a{};
		cin >> a;
		if (a == -1)
		{
			root = i;
		}
		else
		{
			adj[a].push_back(i);
		}
	}
	cin >> ignNode;

	dfs(root);
	cout << result;
}
/*
9
-1 0 0 5 2 4 4 6 6
4

*/