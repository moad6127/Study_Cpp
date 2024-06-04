#include <bits/stdc++.h>

using namespace std;

int N, M, K, T, a, b;

int f[301], dp[301][301];
vector<pair<int, int>> v;

int Func(int here, int num, int prev)
{
	if (here == v.size())
	{
		return 0;
	}
	if (dp[here][num])
	{
		return dp[here][num];
	}

	int cost = max(0, T - v[here].second);
	int real_cost = (prev >= cost) ? 0 : cost - prev;

	if (num - real_cost >= 0)
	{
		return dp[here][num] = max(Func(here + 1, num - real_cost, cost) + v[here].first, Func(here + 1, num, 0));
	}
	else
	{
		return dp[here][num] = Func(here + 1, num, 0);
	}

}
int main()
{
	cin >> N >> M >> K >> T;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		for (int j = a; j < b; j++)
		{
			f[j] = min(T, ++f[j]);
		}
	}
	int temp = f[1];
	int count = 1;
	for (int i = 2; i <= N; i++)
	{
		if (temp != f[i])
		{
			v.push_back({ count,temp });
			count = 0;
			temp = f[i];
		}
		count++;
	}
	v.push_back({ count, temp });
	cout << Func(0, K, 0);
}