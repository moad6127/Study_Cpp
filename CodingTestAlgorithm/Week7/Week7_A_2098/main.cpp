#include <bits/stdc++.h>

using namespace std;
int N ,dp[16][1<<16],dist[16][16];
int tsp(int here, int visited)
{
	if (visited == (1 << N) - 1)
	{
		return dist[here][0] ? dist[here][0] : 987654321;
	}
	int& ret = dp[here][visited];
	if (ret != -1)
	{
		return ret;
	}
	ret = 987654321;
	for (int i = 0; i < N; i++)
	{
		if (visited & (1 << i))
		{
			continue;
		}
		if (dist[here][i] == 0)
		{
			continue;
		}
		ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]);
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> dist[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1);
}