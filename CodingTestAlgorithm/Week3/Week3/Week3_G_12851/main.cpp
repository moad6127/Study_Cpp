#include <bits/stdc++.h>

using namespace std;

int N, K;

const int dx[2] = { -1, 1 };

int main()
{
	cin >> N >> K;
	vector<pair<int, int>> visited(300000, { -1,0 });

	queue<int> q;
	q.push(N);
	visited[N] = { 0,1 };
	if (N > K)
	{
		cout << N - K << '\n' << 1;
		return 0;
	}

	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int nx{};
			if (i < 2)
			{
				nx = now + dx[i];
			}
			else
			{
				nx = now * 2;
			}

			if (nx < 0 || nx >= K * 3)
			{
				continue;
			}
			if (visited[nx].first == -1)
			{
				visited[nx].first = visited[now].first + 1;
				visited[nx].second += visited[now].second;
				q.push(nx);
			}
			else
			{
				if (visited[nx].first == visited[now].first + 1)
				{
					visited[nx].second += visited[now].second;
				}
			}
		}
	}

	cout << visited[K].first<< '\n' << visited[K].second;
}