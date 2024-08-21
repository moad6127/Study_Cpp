#include <bits/stdc++.h>

using namespace std;
int n, m;
int x, y;
int visited[100001];
int v[100001];
bool flag;
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x]++;
		v[y]--;
	}
	for (int i = 1; i <= n; i++)
	{
		v[i] += i;
		visited[v[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] >= 2)
		{
			flag = 1;
		}
	}
	if (flag)
	{
		cout << -1;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cout << v[i] << " ";
		}
	}
}