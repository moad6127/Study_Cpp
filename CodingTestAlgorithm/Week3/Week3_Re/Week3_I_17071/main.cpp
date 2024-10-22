#include <bits/stdc++.h>

using namespace std;
int n, k;
int visited[2][500004];
int cnt{ 1 };
bool flag;
int main()
{
	cin >> n >> k;
	if (n == k)
	{
		cout << 0 << '\n';
		return 0;
	}
	queue<int> q;
	q.push(n);
	visited[0][n] = 1;
	while (q.size())
	{
		k += cnt;
		if (k > 500000)
		{
			break;
		}
		if (visited[cnt % 2][k])
		{
			flag = true;
			break;
		}
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int x = q.front();
			q.pop();
			for (int nx : {x + 1, x - 1, x * 2})
			{
				if (nx < 0 || nx> 500000 || visited[cnt % 2][nx])
				{
					continue;
				}
				visited[cnt % 2][nx] = visited[(cnt + 1) % 2][x] + 1;
				if (nx == k)
				{
					flag = true;
					break;
				}
				q.push(nx);
			}
			if (flag)
			{
				break;
			}
		}
		if (flag)
		{
			break;
		}
		cnt++;
	}
	if (flag)
	{
		cout << cnt << '\n';
	}
	else
	{
		cout << -1;
	}

}