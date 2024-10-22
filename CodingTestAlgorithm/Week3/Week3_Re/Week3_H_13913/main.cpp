#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[300000];
int prev_num[300000];
void bfs(int num)
{
	queue<int> q;
	q.push(num);
	visited[num] = 1;
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int nx : {now + 1, now - 1, now * 2})
		{
			if (nx < 0 || nx >= 200004)
			{
				continue;
			}
			if (!visited[nx])
			{
				q.push(nx);
				visited[nx] = visited[now] + 1;
				prev_num[nx] = now;
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	if (n == k)
	{
		cout << 0 << '\n';
		cout << n << '\n';
		return 0;
	}
	bfs(n);
	cout << visited[k] - 1<<'\n';
	vector<int> pr{k};
	int pre = prev_num[k];
	pr.push_back(pre);
	while (true)
	{
		if (pre == n)
		{
			break;
		}
		pre = prev_num[pre];
		pr.push_back(pre);
	}
	reverse(pr.begin(), pr.end());
	for (auto e : pr)
	{
		cout << e << " ";
	}
}