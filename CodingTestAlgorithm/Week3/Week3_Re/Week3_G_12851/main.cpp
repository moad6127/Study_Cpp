#include<bits/stdc++.h>

using namespace std;
int n, k;
int a[300000];
int cnt[300000];
int result;
const int dx[]{ -1, 1, 0};
void bfs(int nums)
{
	queue<int> q;
	q.push(n);
	a[n] = 1;
	cnt[n] = 1;
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int nx = now + dx[i];
			if (i == 2)
			{
				nx = now * 2;
			}
			if (nx < 0 || nx> 100000)
			{
				continue;
			}
			if (!a[nx])
			{
				q.push(nx);
				cnt[nx] += cnt[now];
				a[nx] = a[now] + 1;
			}
			else if (a[nx] == a[now] + 1)
			{
				cnt[nx] += cnt[now];
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	bfs(n);
	cout << a[k]  - 1<< '\n';
	cout << cnt[k];
}