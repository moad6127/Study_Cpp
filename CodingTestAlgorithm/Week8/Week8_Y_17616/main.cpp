#include <bits/stdc++.h>

using namespace std;

int n, m, X;
int a, b;
int visited[100004];
vector<int> h[100004], l[100004];
int bfs(int here, vector<int> adj[])
{
	queue<int>q;
	visited[here] = 1;
	q.push(here);
	int result{};
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int next : adj[now])
		{
			if (visited[next])
			{
				continue;
			}
			visited[next] = 1;
			q.push(next);
			result++;
		}
	}

	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> X;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		h[a].push_back(b);
		l[b].push_back(a);
	}
	int temp1 = bfs(X, l);
	fill(visited, visited + 100004, 0);
	int temp2 = bfs(X, h);

	cout << temp1 + 1 << " " << n - temp2;
}