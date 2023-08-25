#include <bits/stdc++.h>


using namespace std;

int N, K;
int visited[200004];
int Prev[200004];
int main()
{
	cin >> N >> K;
	visited[N] = 1;
	queue<int> q;
	q.push(N);
	while (q.size())
	{
		int now = q.front();
		q.pop();

		if(now == K)
		{
			break;
		}

		for (int nx : {now + 1, now - 1, now * 2})
		{
			if (nx >= 200004 || nx < 0)
			{
				continue;
			}
			if (visited[nx])
			{
				continue;
			}
			visited[nx] = visited[now] + 1;
			q.push(nx);
			Prev[nx] = now;
		}
	}
	vector<int> trace;
	for (int i = K; i != N; i = Prev[i])
	{
		trace.push_back(i);
	}
	trace.push_back(N);
	reverse(trace.begin(), trace.end());
	cout << visited[K] - 1 << '\n';
	for (auto e : trace)
	{
		cout << e << " ";
	}

}


