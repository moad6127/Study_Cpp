#include <bits/stdc++.h>

using namespace std;

long long N, M, a[10004], lo, hi = 60000000004, result, mid, temp;

bool check(long long mid)
{
	temp = M;
	for (long long i = 0; i < M; i++)
	{
		temp += mid / a[i];
	}

	return temp >= N;
}

int main()
{
	cin >> N >> M;
	for (long long i = 0; i < M; i++)
	{
		cin >> a[i];
	}
	if (N <= M)
	{
		cout << N;
		return 0;
	}

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check(mid))
		{
			result = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	temp = M;
	for (long long i = 0; i < M; i++)
	{
		temp += (result - 1) / a[i];
	}

	for (long long i = 0; i < M; i++)
	{
		if (result % a[i] == 0)
		{
			temp++;
		}
		if (temp == N)
		{
			cout << i + 1;
			return 0;
		}
	}
}